/*
2. 计算两个正整数n和m的乘积有一个很有名的算法称为俄式乘法,其思想是利用了一个规模是n的解和一个规模是n/2的解之间的关系:
n×m =n/2×2m(当n是偶数),或:n×m=(n-1)/2×2m+m(当n是奇数),并以1×m=m作为算法结束的条件。
据说19世纪的俄国农夫使用该算法并因此得名,这个算法也使得乘法的硬件实现速度非常快,因为只使用移位就可以完成二进制数的折半和加倍。
请设计算法实现俄式乘法。
*/

#include <iostream>
using namespace std;
int fun(int n,int m){
	int sum=0;  
   	int temp=m;  
   	while(n!=1){
   		if(n%2==0){  //如果n是偶数,乘积为m*2^(n/2)
			m=m*2;
      		n=n/2;
		}else{    //如果n是奇数 
			m=m*2;   
			sum=sum+temp;   
			n=(n-1)/2;  
		}    
		temp=m;//记录倒数第二个m的值   
	}  
	return sum+m;
}  

int main() {   
	int a,b;
	cout<<"Input a:";
	cin>>a;
	cout<<"Input b:";
	cin>>b;
	cout<<"Reasult: a * b = "<<fun(a,b)<<endl; 
} 
