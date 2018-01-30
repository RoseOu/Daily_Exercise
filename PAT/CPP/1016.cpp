/*
1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/

#include <iostream>
#include <math.h>
using namespace std;

long int countD(long int A, int DA){
	int yu=A%10, shang=A, flag=0;
	long int PA=0;
	while(shang!=0){
		if(yu==DA){
			PA = yu * pow(10,flag) + PA;
			flag = flag + 1;
		}
		shang = shang/10;
		yu = shang%10;
	}
	return PA;
}

int main(){
	long int A, B, PA, PB;
	int DA,DB;

	cin >> A >> DA >> B >> DB;
	PA = countD(A,DA);
	PB = countD(B,DB);
	
	cout<<PA+PB;

	return 0;
}