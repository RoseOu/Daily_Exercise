/*
1009. 说反话 (20)

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，
其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <istream>
using namespace std;

vector <string> reverse_list(vector <string> wlist){
	vector <string> nlist;
	int j;
	for(j=0;j<wlist.size();j++){
		nlist.push_back(wlist.at(wlist.size()-1-j));
	}
	return nlist;
}

int main(){
	vector <string> wlist;
	string singlestr,linestr;
	getline(cin,linestr);
	stringstream str(linestr);
	while(str>>singlestr){
		wlist.push_back(singlestr);
	}
	wlist=reverse_list(wlist);
	for(int i=0;i<wlist.size();i++){
		cout<<wlist.at(i);
		if(i!=wlist.size()-1){
			cout<<" ";
		}
	}
}