#coding:utf-8
'''
1003. 我要通过！(20)

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，
系统就输出“答案正确”，否则输出“答案错误”。得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，
字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
'''

def judge(string):
	string=string.upper()
	m=0
	n=0
	for i in string:
		if i not in ['P','A','T','']:
			return "NO"
	if 'A' not in string or 'P' not in string or 'T' not in string:
		return "NO"
	for g in string:
		if g == 'P':
			m=m+1
		elif g == 'T':
			n=n+1
	if m>1 or n>1:
		return "NO"
	if "PAT" in string:
		dstr=string.split("PAT")
		if dstr[0]!=dstr[1]:
			return "NO"
		else:
			if dstr[0] == '':
				return "YES"
			else:
				for j in dstr[0]:
					if j not in ['A','']: 
						return "NO"
		return "YES"
	try:
		strfront=string.split('P')
		strback=strfront[1].split('T')
		a=strfront[0]
		b=strback[0]
		c=strback[1]
	except:
		return "NO"
	if 'A' in b:
		b=b[:-1]
	else:
		return "NO"
	if a in c:
		c=c[:-len(a)]
	else:
		return "NO"
	str=a+'P'+b+'T'+c
	if judge(str)=='YES':
		return "YES"
	else:
		return "NO"

def main():
	i=0
	strlist=[]
	n=input()
	if n<10:
		while i<n:
			string=raw_input()
			if len(string)<=100:
				strlist.append(string)
				i=i+1
		for s in strlist:
			print judge(s)

if __name__ == '__main__':
	main()