/*
1013. 数素数

令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> prime_num(10004);

void prime_number_list(){
	int index=0;
	int num=2;
	while(index<=10004){
		if(num%2==0 && num!=2){
			num=num+1;
			continue;
		}
		int factor=0;
		for(factor=0;factor<sqrt(index);factor++){
			if(num%prime_num[factor] == 0){
				break;
			}
		}
		if(factor>=sqrt(index)){
			prime_num[index]=num;
			index=index+1;
		}
		num=num+1;
	}
}


int main(){
	int m,n;
	cin>>m>>n;
	prime_number_list();
	for(int i=m;i<=n;++i){
		cout<<prime_num[i-1];
		if((i-m+1) % 10 == 0 || i == n){
			cout<<endl;
		}else{
			cout<<' ';
		}
	}
	return 0;
}
