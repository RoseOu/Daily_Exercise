/*
实验项目——八枚硬币问题
1.实验题目
在八枚外观相同的硬币中，有一枚是假币，并且已知假币与真币的重量不同，但不知道假币与真币相比较轻还是较重。
可以通过一架天平来任意比较两组硬币，设计一个高效的算法来检测出这枚假币。
2.实验目的
（1）深刻理解并掌握减治法的设计思想；
（2）提高应用减治法设计算法的技能；
（3）理解这样一个观点：建立正确的模型对于问题的求解是非常重要的。
3.实验要求
（1）设计减治算法实现八枚硬币问题；
（2）设计实验程序，考察用减治技术设计的算法是否高效；
（3）扩展算法，使之能处理n枚硬币中有1枚假币的问题。
*/

#include <iostream>
using namespace std;

void Coin(int *coins,int *fcoin){
	if(coins[0]+coins[1]+coins[2]>coins[3]+coins[4]+coins[5]){
		if(coins[0]+coins[4]>coins[1]+coins[3]){
			if(coins[0]>coins[7]){
				fcoin[0]=0;
				fcoin[1]=1;
			}else if(coins[0]==coins[7]){
				fcoin[0]=3;
				fcoin[1]=0;
			}
		}else if(coins[0]+coins[4]<coins[1]+coins[3]){
			if(coins[1]>coins[7]){
				fcoin[0]=1;
				fcoin[1]=1;
			}else if(coins[1]==coins[7]){
				fcoin[0]=4;
				fcoin[1]=0;
			}
		}else{
			if(coins[2]>coins[7]){
				fcoin[0]=2;
				fcoin[1]=1;
			}else if(coins[2]==coins[7]){
				fcoin[0]=5;
				fcoin[1]=0;
			}
		}
	}else if(coins[0]+coins[1]+coins[2]<coins[3]+coins[4]+coins[5]){
		if(coins[0]+coins[4]>coins[1]+coins[3]){
			if(coins[4]>coins[7]){
				fcoin[0]=4;
				fcoin[1]=1;
			}else if(coins[4]==coins[7]){
				fcoin[0]=1;
				fcoin[1]=0;
			}
		}else if(coins[0]+coins[4]<coins[1]+coins[3]){
			if(coins[3]>coins[7]){
				fcoin[0]=3;
				fcoin[1]=1;
			}else if(coins[3]==coins[7]){
				fcoin[0]=0;
				fcoin[1]=0;
			}
		}else{
			if(coins[5]>coins[7]){
				fcoin[0]=5;
				fcoin[1]=1;
			}else if(coins[5]==coins[7]){
				fcoin[0]=2;
				fcoin[1]=0;
			}
		}
	}else{
		if(coins[6]>coins[7]){
			if(coins[6]>coins[0]){
				fcoin[0]=6;
				fcoin[1]=1;
			}else if(coins[6]==coins[0]){
				fcoin[0]=7;
				fcoin[1]=0;
			}
		}else if(coins[6]<coins[7]){
			if(coins[7]>coins[0]){
				fcoin[0]=7;
				fcoin[1]=1;
			}else if(coins[7]==coins[0]){
				fcoin[0]=6;
				fcoin[1]=0;
			}
		}
	}
}

int main(){
	int coins[8];
	int fcoin[2]; //fcoin[0]存放假币的顺序，fcoin[1]存放硬币重量是较重还是较轻(1为较重，0为较轻)
	string weight;
	cout<<"Input the weight of coins:";
	for(int i=0;i<8;i++){
		cin>>coins[i];
	}
	Coin(coins,fcoin);
	if(fcoin[1]==1){
		weight="heavier";
	}else if(fcoin[1]==0){
		weight="lighter";
	}
	cout<<"No "<<fcoin[0]+1<< " coin is a "<<weight<<" fake coin!"<<endl;
}
