#include <iostream>
using namespace std;

int MaxSubsegment(int *a,int left,int right){
    int center,i;
    int sum,left_sum,right_sum;
    int left_max,right_max;
    center=(left+right)/2;
    if(left==right){
        return a[left]>0 ? a[left] : 0;
    }
    else
    {
        left_sum=MaxSubsegment(a,left,center);
        right_sum=MaxSubsegment(a,center+1,right);

        sum=0;
        left_max=0;
        for(i=center;i>=left;i--){
            sum=sum+a[i];
            if(sum>left_max)
                left_max=sum;
        }

        sum=0;
        right_max=0;
        for(i=center+1;i<=right;i++){
            sum=sum+a[i];
            if(sum>right_max)
                right_max=sum;
        }

        sum=right_max+left_max;
        if(sum<left_sum){
            sum=left_sum;
        }
        if(sum<right_sum){
            sum=right_sum;
        }
    }
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
	result=MaxSubsegment(num,0,length-1);
	cout<<result;

	return 0;
}