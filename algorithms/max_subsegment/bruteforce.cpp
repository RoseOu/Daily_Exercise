#include <iostream>
using namespace std;

int MaxSubsegment(int *num,int length){
	int maxsum=0,sum=0;

	for(int i=0;i<length;i++){
		for(int j=i;j<length;j++){
			sum=sum+num[j];
			if(sum>maxsum){
				maxsum=sum;
			}
		}
		sum=0;
	}
	return maxsum;
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
