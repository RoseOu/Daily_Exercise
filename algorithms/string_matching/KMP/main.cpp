#include <iostream>
#include <string>
using namespace std;

void GetNext(char T[],int next[]){
	int i,j,len;
	next[0]=-1;
	for(j=1;T[j]!='\0';j++){
		for(len=j-1;len>=1;len--){
			for(i=0;i<len;i++){
				if(T[i]!=T[j-len+i]) break;
			}
			if(i==len){
				next[j]=len;
				break;
			}
		}
		if(len<1){
			next[j]=0;
		}
	}
}

int KMP(char S[],char T[]){
	int i=0,j=0;
	int next[80];
	GetNext(T,next);
	while(S[i]!='\0'&&T[j]!='\0'){
		if(S[i]==T[j]){
			i++;
			j++;
		}else{
			j=next[j];
			if(j==-1){
				i++;
				j++;
			}
		}
	}
	if(T[j]=='\0'){
		return (i-strlen(T)+1);
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

	cout<<"result:  "<<KMP(S,T)<<endl;
	return 0;
}
