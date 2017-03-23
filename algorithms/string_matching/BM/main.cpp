#include <iostream>
#include <string>
using namespace std;

int dist(char ch,char T[],int m)
{
    int i=m-1;
    if(ch==T[i])
      return m;
    i--;
    while(i >= 0)
    {
      if(ch == T[i])
         return m-1-i;
      else
         i--;
    }
    return m;
}

int BM(char S[],char T[],int n,int m){
	int i,j;
	i=m-1;
	while(i<=n-1){
		j=m-1;
		while(j>=0 && S[i]==T[j]){
			j=j-1;
			i=i-1;
		}
		if(j<0) 
			return i+2;
		else{
			i=i+dist(S[i],T,m);
		}
	}
	return 0;
}

int main(){
	string s,t;
	char *S,*T;
	int n,m,i,j;

	cout<<"Input S: ";
	cin>>s;
	S=const_cast<char*>(s.c_str());
	cout<<endl;
	n=strlen(S);

	cout<<"Input T: ";
	cin>>t;
	T=const_cast<char*>(t.c_str());
	cout<<endl;
	for(j=0;T[j]!='\0';j++);
	m=strlen(T);

	cout<<"result:  "<<BM(S,T,n,m)<<endl;
	return 0;
}