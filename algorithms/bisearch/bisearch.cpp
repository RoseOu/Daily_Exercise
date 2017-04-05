/*
修改折半查找算法使之能够进行范围查找。所谓范围查找是要找出在给定值a和b之间的所有元素。
*/

#include <iostream>
using namespace std;

void BiSearch(int r[],int n,int a,int b,int *mids){
	int low=0,high=n-1;
	int mid,mid1=-1,mid2=-1;
	int max,min;

	if(a>=b){
		max=a;
		min=b;
	}else{
		max=b;
		min=a;
	}
	while(low<=high){
		mid=(low+high)/2;
		if(r[mid]<min){
			low=mid+1;
		}else if(r[mid]>min){
			high=mid-1;
		}else{
			mid1=mid;
			break;
		}
	}
	low=mid1+1;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(r[mid]<max){
			low=mid+1;
		}else if(r[mid]>max){
			high=mid-1;
		}else{
			mid2=mid;
			break;
		}
	}
	mids[0]=mid1;
	mids[1]=mid2;
}


int main(){
	int *r,*mids,min,max,n;

	cout<<"Input the number of elements: ";
	cin>>n;
	r=new int[n];
	cout<<"Input the elements: ";
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	cout<<"Input the the lower bound of the range:";
	cin>>min;
	cout<<"Input the the upper bound of the range:";
	cin>>max;

	mids=new int[2];
	BiSearch(r,n,min,max,mids);
	cout<<"The elements in the range:";
	for(int i=mids[0]+1;i<mids[1];i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;

	return 0;
}
