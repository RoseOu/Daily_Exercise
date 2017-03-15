#coding:utf-8
'''
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
'''
def sum(n):
	num=0
	x=n
	while x/10 != 0:
		num=num+x%10
		x=x/10
	num=num+x
	return num

def exchange(num):
	numlist=[]
	y=num
	dict={1:'yi',2:'er',3:'san',4:'si',5:'wu',
	      6:'liu',7:'qi',8:'ba',9:'jiu',0:'ling'}
	while y/10 != 0:
		numlist.append(dict[y%10])
		y=y/10
	numlist.append(dict[y%10])
	numlist.reverse()
	numstr=' '.join(numlist)
	return numstr

def main():
	n=input()
	if n<10**100:
		num=sum(n)
		numstr=exchange(num)
		print numstr

if __name__ == '__main__':
	main()