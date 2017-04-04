#coding:utf-8
'''
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。
例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234

输入样例2：
23
输出样例2：
SS123
'''

def exchange(n):
	bnum=n/100
	snum=(n-bnum*100)/10 if n>=100 else n/10
	gnum=n%10

	b=1
	bstr=""
	while b<=bnum:
		bstr=bstr+"B"
		b=b+1

	s=1
	sstr=""
	while s<=snum:
		sstr=sstr+"S"
		s=s+1
	i=1

	gstr=""
	while i<=gnum:
		gstr=gstr+str(i)
		i=i+1
	result="".join([bstr,sstr,gstr])
	return result

def main():
	num=input()
	if num<1000:
		result=exchange(num)
		print result

if __name__ == '__main__':
	main()
