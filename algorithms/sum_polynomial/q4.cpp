/*
4.设计递归算法求多项式A(x)=an*xn +an-1*xn-1 +…+a1*x+a0的值,建立该算法的递推式并求解。
(提示:将A(x)=an*xn +an-1*xn-1 +…+a1*x+a0转化为A(x)=(…(an*x+an-1*x+…+a1*x+a0))
*/

#include <iostream>
using namespace std;

void sum(int x,int *a,int &ai,int &i){
	while(i>=1){
		ai=ai*x+a[i-1];
		i=i-1;
		sum(x,a,ai,i);
	}
}

int main(){
	int n,x,*a;        //n为多项式系数下标,x为变量值,数组a存放每一项的系数
	int ai,i;        //存储当前计算的值

	cout<<"Input n: ";
	cin>>n;
	a=new int[n+1];
	for(int j=0;j<=n;j++){
		cout<<"Input a"<<j<<": ";
		cin>>a[j];      //数组a[i]存放每一项的系数
	}
	cout<<"Input x:";
	cin>>x;
	ai=a[n];
	i=n;
	sum(x,a,ai,i);
	cout<<"The result: "<<ai<<endl;
	return 0;
}