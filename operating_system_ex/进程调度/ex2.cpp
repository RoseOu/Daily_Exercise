/*
1.题目：进程PCB队列的组织、管理（以及进程调度）模拟实验。
2.问题描述：针对进程调度活动，研究进程PCB队列的动态组织与管理问题。本实验将利用伙伴系统来组织进程PCB池和动态的进程PCB队列。
从初始化快照、某一进程运行前的快照、运行后的快照等状态出发，结合进程操作原语的实现，考虑进程PCB队列的组织、
变化及其队列管理方面的问题。具体内容如下：
（1）刚完成系统运行初始化时的快照：运行中的PCB队列为空，PCB池队列为满。
（2）某一进程运行前快照：运行中的PCB队列非空，PCB池队列非满。PCB队列在上一次执行之后的格局状态。
（3）某一进程运行后快照：运行中的PCB队列非空，PCB池队列非满。PCB队列在上一次执行之后，在执行一次原语之后的格局状态。
3.要求：（1）基本要求，事先构造一个PCB总链队列，可对该队列进行正常的维护，即当PCB状态变化时，在总链队列的基础上，
实现菜单式管理和进程原语操作，实现创建、撤销、时间片到、挂起进程和激活进程等基本进程原语，以实现PCB的就绪队列、
等待队列的组织与管理；（2）扩展一，实现利用伙伴系统策略对于资源池PCB队列和运行中的PCB队列的组织与管理；
（3）扩展二，考虑利用进程调度程序来实现对CPU的控制与调度过程；（4）扩展三，实现PCB的回收算法并考虑到PCB空白块的合并问题。
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>


using namespace std;

//进程状态
#define WAIT 0       //等待状态(阻塞状态)
#define READY 1      //就绪状态
#define RUNNING 2    //运行状态

//阻塞原因（chan）
#define NEED_IO 1               //需要进行I/O操作
#define MEMORY_NOT_ENOUGH 2     //内存不足

//系统配置
static int PID=1000;       //进程号从1000开始
static int TIMESLICE=5;    //假设分配给每个进程时间片都为5
static int ALLMEMORY=10;      //用户可用内存为10

class PCB;           //PCB
class WaitQueue;     //各种不同阻塞原因的等待序列

class WaitQueue{
	private:
		int chan;              //阻塞原因
	public:
		list<PCB> waitqueue;   //PCB等待序列

		WaitQueue(int chan){
			this->chan=chan;
		}

		int get_chan(){       //返回阻塞原因
			return this->chan;
		}

};

class PCB{
	private:
		string name; //进程名
		pid_t pid;   //进程号
		int prio;    //进程优先数(数字越小优先数越高)
		int cputime; //进程占用CPU时间
		int runtime; //进程已运行时间
		int status;  //进程状态
		int io;      //进程是否需要进行I/O操作，1为需要，0为不需要
		int memory;  //进程需要占用的内存

	public:
		string get_name(){
			return this->name;
		}

		pid_t get_pid(){
			return this->pid;
		}

		int get_prio(){
			return this->prio;
		}

		int get_cputime(){
			return this->cputime;
		}

		int get_runtime(){
			return this->runtime;
		}

		int get_status(){
			return this->status;
		}

		int get_io(){
			return this->io;
		}

		int get_memory(){
			return this->memory;
		}


		//进程创建
		static PCB do_fork(list<PCB> &pool,list<PCB> &ready,list<PCB> &all,string name,int prio,int cputime,int io,int memory){
			PCB pcb;
			if(!pool.empty()){       //当PCB池不为空时
				pcb=pool.front();    //从PCB池中取出一个空PCB
				pool.pop_front();
				pcb.name=name;       //初始化进程名
				pcb.pid=PID;         //初始化进程号
				PID=PID+1;           //系统分配的进程号加1
				pcb.prio=prio;       //初始化优先数
				pcb.cputime=cputime; //初始化需要运行的时间
				pcb.io=io;           //初始化是否需要I/O操作
				pcb.memory=memory;   //初始化需要占用的内存
				pcb.runtime=0;       //一开始已运行时间为0
				pcb.status=READY;    //设进程状态为就绪
				ready.push_back(pcb);  //将PCB放进就绪序列
				all.push_back(pcb);     //将PCB放进PCB总链
			}
			PCB::priosort(ready);     //将就绪队列里的PCB按优先数排列
			return pcb;
		}

		//进程调度
		static PCB schedule(vector<WaitQueue> &all_queue,list<PCB> &ready){
			PCB runpcb;
			if(!ready.empty()){        //当就绪队列不为空
				runpcb=ready.front();  //取出就绪队列中第一个PCB
				ready.pop_front();
				runpcb.status=RUNNING;  //将状态设为正在运行
			}
			return runpcb;              //返回该PCB
		}

		//进程唤醒
		static int wake_up(vector<WaitQueue> &all_queue,list<PCB> &ready,int chan){
			PCB npcb;
			int i;
			for(i=0;i<all_queue.size();i++){
				if(all_queue[i].get_chan()==chan){            //找到该阻塞原因相应的等待序列
					while(!all_queue[i].waitqueue.empty()){   //当该等待序列不为空
						PCB npcb;
						npcb=all_queue[i].waitqueue.front();  //将等待序列里的PCB一个个放进就绪序列，状态设为就绪状态
						npcb.status=READY;
						ready.push_back(npcb);
						all_queue[i].waitqueue.pop_front();
					}
					PCB::priosort(ready);
				}
			}
			return 0;
		}


		//进程挂起
		static PCB susp(vector<WaitQueue> &all_queue,list<PCB> &ready,PCB &runpcb,int chan,double totaltime){
			int i;
			PCB npcb;
			for(i=0;i<all_queue.size();i++){
				if(all_queue[i].get_chan()==chan){    //找到该阻塞原因相应的等待序列
					runpcb.status=WAIT;                //将其设为阻塞状态
					runpcb.runtime=totaltime+runpcb.get_runtime();  //并保存进程的已运行时间
					all_queue[i].waitqueue.push_back(runpcb);       //将进程放进该阻塞原因相应的等待序列
					npcb=PCB::schedule(all_queue,ready);         //转进程调度程序
				}

			}
			return npcb;     //返回下一个运行的进程
		}

		//时钟中断程序
		static int time_interrupt(PCB &runpcb,double totaltime,list<PCB> &ready){
			//将其重新放进就绪队列，且保存已运行时间，且优先数加1（即降低了优先级）
			runpcb.status=READY;
			runpcb.prio=runpcb.prio+1;
			runpcb.runtime=totaltime+runpcb.get_runtime();
			ready.push_back(runpcb);
			PCB::priosort(ready);
			return 0;
		}

		//自定义比较函数
		static bool cmp(PCB p1,PCB p2){
			return p1.prio<p2.prio;
			
		}

		//将就绪队列（ready）里的进程按优先级从高到低排列
		static int priosort(list<PCB> &ready){
			ready.sort(cmp);
			return 0;
		}
};


int main(){
	list<PCB> pool(50);     //定义一个PCB池，里面有50个空的PCB
	list<PCB> ready;        //就绪队列
	list<PCB>::iterator it;  //迭代器
	list<PCB> all;          //PCB总链
	vector<WaitQueue> all_queue;  //所有等待序列
	WaitQueue needio(NEED_IO);    //需要进行I/O操作的等待序列
	all_queue.push_back(needio);  //将需要进行I/O操作的等待序列放进all_queue
	WaitQueue memory_not(MEMORY_NOT_ENOUGH);    //需要进行I/O操作的等待序列
	all_queue.push_back(memory_not);  //将需要进行I/O操作的等待序列放进all_queue

	PCB runpcb;           //正在运行的进程
	int pcbnum;            //创建进程的个数
	clock_t start,finish;   //用于计算进程运行时间
   	double totaltime;

   	cout<<"---------------------- 创建进程 ----------------------"<<endl;
	cout<<"输入创建的进程个数："<<endl;
	cin>>pcbnum;
	cout<<endl;
	for(int i=0;i<pcbnum;i++){
		PCB pcb;
		string name;
		int prio;
		int cputime;
		int io;
		int memory;
		cout<<"输入进程名字："<<endl;
		cin>>name;
		cout<<"输入进程优先数："<<endl;
		cin>>prio;
		cout<<"输入进程需要运行的时间："<<endl;
		cin>>cputime;
		cout<<"输入进程是否需要进行I/O操作（1为需要，0为不需要）："<<endl;
		cin>>io;
		cout<<"输入进程需要占用的内存："<<endl;
		cin>>memory;
		pcb=PCB::do_fork(pool,ready,all,name,prio,cputime,io,memory); //创建进程
		cout<<endl;
	}

	cout<<"---------------------- 当前就绪队列 ----------------------"<<endl;
	cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
	for(it=ready.begin();it!=ready.end();it++){
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		    <<it->get_cputime()<<"               "<<it->get_io()<<"                "
		    <<it->get_memory()<<"           "<<it->get_status()<<endl;
	}
	cout<<endl;

	cout<<"------------------- 成功执行的进程的执行顺序 -------------------"<<endl;

	while((!ready.empty())){    //当就绪队列不为空
		runpcb=PCB::schedule(all_queue,ready);   //调度进程
		if(runpcb.get_io()==1){    //若进程需要I/O操作，将其挂起放入相应的等待序列
			int chan;
			chan=NEED_IO;
			runpcb=PCB::susp(all_queue,ready,runpcb,chan,totaltime);
		}
		if(runpcb.get_memory()>ALLMEMORY){    //若进程需要的内存太大，将其挂起放入相应的等待序列
			int chan;
			chan=MEMORY_NOT_ENOUGH;
			runpcb=PCB::susp(all_queue,ready,runpcb,chan,totaltime);
		}
		start=clock();        //计算进程运行时间
		finish=clock();
		totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
		while(totaltime<(runpcb.get_cputime()-runpcb.get_runtime())){  //进程正在执行中的时候
			if(runpcb.get_status()==RUNNING){
				finish=clock();
				totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
				if(totaltime>=TIMESLICE){    //当时间片用完
					PCB::time_interrupt(runpcb,totaltime,ready);  //调用时钟中断程序
				}
			}else{
				break;
			}
		}
		if(runpcb.get_status()==RUNNING){
			cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
			cout<<runpcb.get_name()<<"        "<<runpcb.get_pid()<<"      "<<runpcb.get_prio()<<"         "
		    	<<runpcb.get_cputime()<<"               "<<runpcb.get_io()<<"                "
		    	<<runpcb.get_memory()<<"           "<<runpcb.get_status()<<endl;
		}
	}

	cout<<"------------------- 需要进行I/O操作的等待队列 -------------------"<<endl;
	for(it=all_queue[0].waitqueue.begin();it!=all_queue[0].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
	    	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}

	cout<<"---------------------- 内存不足的等待队列 ----------------------"<<endl;
	for(it=all_queue[1].waitqueue.begin();it!=all_queue[1].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
		   	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}


	cout<<endl;
	cout<<"                    现可使用I/O资源!!!"<<endl;
	cout<<endl;
	//I/O资源
	int chan1;
	chan1=NEED_IO;
	PCB::wake_up(all_queue,ready,chan1);
	cout<<"------------------- 成功执行的进程的执行顺序 -------------------"<<endl;
	while((!ready.empty())){
		runpcb=PCB::schedule(all_queue,ready);
		if(runpcb.get_status()==RUNNING){
			cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
			cout<<runpcb.get_name()<<"        "<<runpcb.get_pid()<<"      "<<runpcb.get_prio()<<"         "
		    	<<runpcb.get_cputime()<<"               "<<runpcb.get_io()<<"                "
		    	<<runpcb.get_memory()<<"           "<<runpcb.get_status()<<endl;
		}
	}
	cout<<"------------------- 需要进行I/O操作的等待队列 -------------------"<<endl;
	for(it=all_queue[0].waitqueue.begin();it!=all_queue[0].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
	    	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}
	cout<<"---------------------- 内存不足的等待队列 ----------------------"<<endl;
	for(it=all_queue[1].waitqueue.begin();it!=all_queue[1].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
		   	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}


	cout<<endl;
	cout<<"                    现已分配更多内存!!!"<<endl;
	cout<<endl;
	//分配更多内存
	int chan2;
	chan2=MEMORY_NOT_ENOUGH;
	PCB::wake_up(all_queue,ready,chan2);
	cout<<"------------------- 成功执行的进程的执行顺序 -------------------"<<endl;
	while((!ready.empty())){
		runpcb=PCB::schedule(all_queue,ready);
		if(runpcb.get_status()==RUNNING){
			cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
			cout<<runpcb.get_name()<<"        "<<runpcb.get_pid()<<"      "<<runpcb.get_prio()<<"         "
		    	<<runpcb.get_cputime()<<"               "<<runpcb.get_io()<<"                "
		    	<<runpcb.get_memory()<<"           "<<runpcb.get_status()<<endl;
		}
	}
	cout<<"------------------- 需要进行I/O操作的等待队列 -------------------"<<endl;
	for(it=all_queue[0].waitqueue.begin();it!=all_queue[0].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
	    	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}
	cout<<"---------------------- 内存不足的等待队列 ----------------------"<<endl;
	for(it=all_queue[1].waitqueue.begin();it!=all_queue[1].waitqueue.end();it++){
		cout<<"进程名   进程号   优先数  需要运行时间   是否需要I/O操作  需要占用的内存  状态"<<endl;
		cout<<it->get_name()<<"        "<<it->get_pid()<<"      "<<it->get_prio()<<"         "
		   	<<it->get_cputime()<<"               "<<it->get_io()<<"                "
		   	<<it->get_memory()<<"           "<<it->get_status()<<endl;
	}

	return 0;
}