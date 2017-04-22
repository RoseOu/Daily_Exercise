#coding:utf-8
'''
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4

(最后一个测试点还是运行超时啊啊啊啊啊啊)
'''
import math

def solve(numrange):
    num=[]
    count=0
    temp=0
    result=0
    if numrange<=3:
        return result
    else:
        num.append(2)
        num.append(3)
        count=2
        i=4
        while i<=numrange:
            temp=0
            j=2
            while j<=math.sqrt(i):
                if (i%j) == 0:
                    temp = 1
                    break
                j=j+1
            if temp != 1:
                num.append(i)
                count=count+1
            i=i+1
        k=0
        while k<count-1:
            if (num[k+1] - num[k]) == 2:
                result=result+1
            k=k+1
        return result

if __name__ == '__main__':
    numrange=int(input())
    result=solve(numrange)
    print(result)
