/*
(py3)
1012. 数字分类

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector <string> sort(vector <int> numlist){
	vector <string> result(5);
	vector <int> a(5,0);
	vector <int> flag(5,0);
	stringstream ss;
	string str;
    int a2index=0,a4c;
 	double a4num=0.0,a4sum=0.0;
 	double a4;
 	for(int i=0;i<numlist.size();i++){
 		if(numlist[i]%5==0){
 			if(numlist[i]%2==0){
 				flag[0]=1;
 				a[0]=a[0]+numlist[i];
 				result[0]=to_string(a[0]);
 			}
 		}else if(numlist[i]%5==1){
 			flag[1]=1;
 			if(a2index%2==0){
 				a[1]=a[1]+numlist[i];
 			}else{
 				a[1]=a[1]-numlist[i];
 			}
            a2index=a2index+1;
            result[1]=to_string(a[1]);
 		}else if(numlist[i]%5==2){
 			flag[2]=1;
 			a[2]=a[2]+1;
 		}else if(numlist[i]%5==3){
 			flag[3]=1;
            a4sum=a4sum+numlist[i];
            a4num=a4num+1;
 		}else if(numlist[i]%5==4){
 			flag[4]=1;
            if(numlist[i]>a[4]){
            	a[4]=numlist[i];
            }
 		}
 	}
	if(flag[3]==1){
        a4=a4sum/a4num;
        a4c=(a4+0.05)*10;
        a4=double(a4c)/10;
	}
	for(int j=0;j<result.size();j++){
		if(flag[j]==0){
			result[j]='N';
		}else{
			if(j==3){
				ss << a4;
				ss >> str;
				result[j]=string(str);
			}else{
				result[j]=to_string(a[j]);
			}
		}
	}
    return result;
}

int main(){
	int n,num;
	vector <int> numlist;
	vector <string> result(5);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		numlist.push_back(num);
	}
	result=sort(numlist);
	for(int j=0;j<result.size();j++){
		cout<<result[j];
		if(j!=result.size()-1){
			cout<<" ";
		}
	}
	return 0;
}
