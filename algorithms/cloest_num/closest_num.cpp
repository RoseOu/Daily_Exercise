//设计算法找出数组中相差最小的两个元素（称为最接近数）的差。要求分别给出伪代码和C++描述。

#include <iostream>
using namespace std;

typedef int ElemType;

void bubble_sort(ElemType *elem,int num);
void Find(ElemType *elem,int num,ElemType &min,ElemType &num1,ElemType &num2);

int main(){
	int i,num;
	ElemType *elem,min,num1,num2;

	cout << "*************Input*************" << endl;
	cout << "Input the number of elements: ";
	cin >> num;
	elem = new ElemType[num];
	cout << "Input the elements:";

	for(i=0;i<num;i++){
		cin >> elem[i];
	}

	bubble_sort(elem,num);

	cout << "*************Result*************" << endl;
	cout << "The sorted elements: ";
	for(i=0;i<num;i++){
		cout << elem[i] << " ";
	}
	cout << endl;

	Find(elem,num,min,num1,num2);
	cout << "Two closest numbers: "<< num1 << " " << num2 <<endl;
	cout << "The diffences between two closest numbers: " << min << endl;

	return 0;
}

//对数组进行冒泡排序
void bubble_sort(ElemType *elem,int num){
	int i,j,lastExchangeIndex;
	ElemType W;

	i=num;
	while(i>1){
		lastExchangeIndex=1;
		for(j=0;j<i-1;j++){
			if(elem[j+1]<elem[j]){
				W=elem[j];
				elem[j]=elem[j+1];
				elem[j+1]=W;
				lastExchangeIndex=j+1;
			}
		}
		i=lastExchangeIndex;
	}
}


//然后计算相邻元素的差并找出最小值
void Find(ElemType *elem,int num,ElemType &min,ElemType &num1,ElemType &num2){
	//min为最接近数的差，num1为最接近数的较小的数，num2为最接近数的较大的数，diff为相邻数的差
	int i;
	ElemType diff;

	min = elem[1]-elem[0];  //初始化min,num1,num2
	num1 = elem[0];
	num2 = elem[1];
	for(i=0;i<num-1;i++){
		diff = elem[i+1]-elem[i];
		if (diff<min){
			min=diff;
			num1=elem[i];
			num2=elem[i+1];
		}
	}
}

