#include <iostream>
#include <string>
using namespace std;

int BF(char S[],char T[]){
	int index=0;
	int i=0,j=0;
	while((S[i]!='\0')&&(T[j]!='\0')){
		if(S[i]==T[j]){
			i++;
			j++;
		}else{
			index++;
			i=index;
			j=0;
		}
	}
	if(T[j]=='\0'){
		return index+1;
	}else{
		return 0;
	}
}

int main(){
	string s,t;
	char *S,*T;

	cout<<"Input S: ";
	cin>>s;
	S=const_cast<char*>(s.c_str());
	cout<<endl;

	cout<<"Input T: ";
	cin>>t;
	T=const_cast<char*>(t.c_str());
	cout<<endl;

	cout<<"result:  "<<BF(S,T)<<endl;
	return 0;
}
