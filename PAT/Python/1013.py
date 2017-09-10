'''
(py3)
1013. 数素数

令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

（测试点4运行超时）
'''

def prime_number_list(m,n):
    prime_num = []
    index=0
    for num in range(2,10001):
        flag=0
        for factor in range(2,int(num/2)+1):
            if num%factor == 0 and num!=factor:
                flag=1
                break;
        if flag==0:
            index=index+1
            if index in range(m,n+1):
                prime_num.append(num)
        if index==n:
            break;
    return prime_num

def main():
    numstr = input().split()
    m = int(numstr[0])
    n = int(numstr[1])
    prime_num = prime_number_list(m,n)
    for i,p in enumerate(prime_num):
        if i==len(prime_num)-1:
            print(p,end='')
        else:
            if (i+1)%10==0:
                print(p,end='\n')
            else:
                print(p,end=' ')

if __name__ == '__main__':
    main()
