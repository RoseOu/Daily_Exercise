/* 
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/


#include <iostream>
#include <math.h>
using namespace std;

int solve(int numrange){
	int num[numrange];
	int count = 0;
	int temp = 0;
	int result=0;
    if (numrange<=3){
    	return result;
    }else{
	    num[0] = 2;
	    num[1] = 3;
	    count = 2;
	    for(int i = 4;i <= numrange;i++){
	        temp = 0;
	        for(int j = 2;j <= sqrt(i); j++){
	            if((i % j) == 0){
	                temp = 1;
	                break;
	            }
	        }
	        if(temp != 1){
	            num[count] = i;
	            count++;
	        }
	    }
	    for(int i = 0;i < count - 1;i++){
	        if((num[i+1] - num[i]) == 2){
	            result++;
	        }
	    }
	    return result;
	}
}

int main()
{
	int numrange;
	int result;
	cin>>numrange;
	result=solve(numrange);
	cout<<result;
	return 0;
}
