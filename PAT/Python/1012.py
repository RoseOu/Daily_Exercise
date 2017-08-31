'''
(py3)
1012. 数字分类

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
'''

def sort(numlist):
    a=[0,0,0,0,0]
    a2index=0
    a4num=0.0
    a4sum=0.0
    flag=[0,0,0,0,0]
    for n in numlist:
        if n%5==0:
            if n%2==0:
                flag[0]=1
                a[0]=a[0]+n
        elif n%5==1:
            flag[1]=1
            if a2index%2==0:
                a[1]=a[1]+n
            else:
                a[1]=a[1]-n
            a2index=a2index+1
        elif n%5==2:
            flag[2]=1
            a[2]=a[2]+1
        elif n%5==3:
            flag[3]=1
            a4sum=a4sum+n
            a4num=a4num+1
        elif n%5==4:
            flag[4]=1
            if n>a[4]:
                a[4]=n
    if flag[3]==1:
        a[3]=round(a4sum/a4num,1)
    for j,f in enumerate(flag):
        if f==0:
            a[j]='N'
    return a

def main():
    numstr=input().split()
    n=int(numstr[0])
    numlist=[int(num) for num in numstr[1:n+1]]
    alist=sort(numlist)
    print(" ".join([str(a) for a in alist]))

if __name__ == '__main__':
    main()

