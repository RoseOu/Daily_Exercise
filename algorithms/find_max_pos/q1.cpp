/*
设计分治算法求一个数组中最大元素的位置.
*/

#include <iostream>
using namespace std;

int FindMaxPos(int *num,int begin,int end){
	int lmaxpos,rmaxpos,mid;
	//mid为数组中间数的索引值,lmaxpos为数组前半部分最大元素的位置,rmaxpos为数组后半部分最大元素的位置
	if(begin==end) return begin;//当起始位置和结束位置相同，则只有一个元素
	mid=(begin+end)/2;
	lmaxpos=FindMaxPos(num,begin,mid); //递归求前半部分最大元素的位置
	rmaxpos=FindMaxPos(num,mid+1,end); //递归求后半部分最大元素的位置
	if(num[lmaxpos]>=num[rmaxpos])   //比较前半部分最大元素和后半部分最大元素，得出最大值
		return lmaxpos;
	else
		return rmaxpos;
}

int main(){
	int n;     //元素个数
	int *num;    //储存元素的数组
	int begin=0,maxpos,end; //begin为起始位置(数组下标)，end为结束位置(数组下标)，maxpos为最大元素的位置(数组下标)
	cout<<"Input the number of elements: ";
	cin>>n;
	num=new int[n];
	cout<<"Input the elements: ";
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	end=n-1;
	maxpos=FindMaxPos(num,begin,end);
	cout<<"The max number position: "<<maxpos;
	return 0;
}