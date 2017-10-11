/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）
是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、
以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，
THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector <string> decodeString(string str1,string str2,string str3,string str4){
	int i,j,k,s;
	stringstream ss;
	string date;
	string hour;
	string second;
	string str0;
	vector <string> result;
	map <char,string> datemap;
	datemap['A']="MON"; datemap['B']="TUE"; datemap['C']="WED"; datemap['D']="THU";
	datemap['E']="FRI"; datemap['F']="SAT"; datemap['G']="SUN";
	map <char,string> hourmap;
	hourmap['A']="10"; hourmap['B']="11"; hourmap['C']="12"; hourmap['D']="13"; hourmap['E']="14";
	hourmap['F']="15"; hourmap['G']="16"; hourmap['H']="17"; hourmap['I']="18"; hourmap['J']="19";
	hourmap['K']="20"; hourmap['L']="21"; hourmap['M']="22"; hourmap['N']="23";

	for(i=0;i<min(str1.length(),str2.length());i++){
		if(str1[i]==str2[i] && str1[i]>='A' && str1[i]<='G'){
			date=datemap[str1[i]];
			s=i;
			break;
		}
	}
	for(k=s+1;k<min(str1.length(),str2.length());k++){
		if(str1[k]==str2[k]){
			if(str1[k]>='0' && str1[k]<='9'){
				ss<<str1[k];
				ss>>str0;
				hour="0"+str0;
				break;
			}else if(str1[k]>='A' && str1[k]<='N'){
				hour=hourmap[str1[k]];
				break;
			}
		}
	}
	for(j=0;j<min(str3.length(),str4.length());j++){
		if (str3[j]==str4[j] && ((str3[j]>='A' && str3[j]<='Z') || (str3[j]>='a' && str3[j]<='z'))){
			if(j<10){
				ss<<j;
				ss>>str0;
				second="0"+str0;
			}else{
				ss<<j;
				ss>>str0;
				second=str0;
			}
			break;
		}
	}
	result.push_back(date);
	result.push_back(hour);
	result.push_back(second);
	return result;
}

int main(){
	string str1,str2,str3,str4;
	vector <string> result;
	cin>>str1>>str2>>str3>>str4;
	result=decodeString(str1,str2,str3,str4);
	cout<<result[0]<<" "<<result[1]<<":"<<result[2];
	return 0;
}


