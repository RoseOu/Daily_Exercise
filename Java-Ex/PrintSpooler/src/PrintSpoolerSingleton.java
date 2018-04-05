
public class PrintSpoolerSingleton{
	private static PrintSpoolerSingleton[] instances=new PrintSpoolerSingleton[]{null,null};

	
	private PrintSpoolerSingleton(){
	}
	
	public static PrintSpoolerSingleton getInstance() throws PrintSpoolerException{
		for (int i=0;i<2;i++){
			if(instances[i]==null){
				System.out.println("创建打印池！");
				instances[i]=new PrintSpoolerSingleton();
				return instances[i];
			}
		}
		throw new PrintSpoolerException("打印池正在工作中！");
		
	}
	
	public void manageJobs(){
		System.out.println("管理打印任务中！");
	}
}
