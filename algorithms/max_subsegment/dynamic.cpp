#include <iostream>
using namespace std;


int MaxSubsegment(int *num,int length)
{
	int sum = 0;
	int *b = new int [length];
	b[0] = num[0];
	for(int i=1; i<length; i++){
		if(b[i-1]>0){
			b[i] = b[i-1] + num[i];
		}else{
			b[i] = num[i];
		}
	}
	for(int j=0; j<length; j++){
		if(b[j]>sum){
			sum=b[j];
		}
	}
	delete []b;	
	return sum;
}

int main(){
	int *num,length,result;

	cout<<"Input the length of num:";
	cin>>length;
	cout<<"Input the numbers:";
	for(int i=0;i<length;i++){
		cin>>num[i];
	}
	result=MaxSubsegment(num,length);
	cout<<result;

	return 0;
}