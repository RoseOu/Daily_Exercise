/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	char *num;
	int sum=0,y,b=0,j;
	int a[3] = {-1, -1, -1};

	string changeStr[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	cin>>str;
	num=new char[100];
	num=const_cast<char*>(str.c_str());
	for(int i=0;i<str.length();i++){
		sum=sum+(int(num[i])-48);
	}

	y=sum;
	while(y/10!=0){
		y=y/10;
		b++;
	}
	y=sum;
	while(y/10!=0){
		int n=1;
		for(int j=0;j<b;j++){
			n=n*10;
		}
		cout<<changeStr[y/n]<<" ";
		y=y%n;
		if(b==2&&y/10==0){
			cout<<changeStr[0]<<" ";
		}
		b--;
	}
	cout<<changeStr[y];
	return 0;
}