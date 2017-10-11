'''
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）
是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、
以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，
THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04
'''

def decodeString(str1,str2,str3,str4):
    date=""
    hour=""
    second=""
    dateDict={"A":"MON", "B":"TUE", "C":"WED", "D":"THU", "E":"FRI", "F":"SAT", "G":"SUN"}
    hourDict={"A":"10", "B":"11", "C":"12", "D":"13", "E":"14", "F":"15", "G":"16", "H":"17",
              "I":"18", "J":"19", "K":"20", "L":"21", "M":"22", "N":"23"}
    for i in range(0,min(len(str1),len(str2))):
        if str1[i]==str2[i] and "A"<=str1[i]<="G":
            date=dateDict[str1[i]]
            s=i
            break
    for k in range(s+1,min(len(str1),len(str2))):
        if str1[k]==str2[k]:
            if "0"<=str1[k]<="9":
                hour="0"+str1[k]
                break
            elif "A"<=str1[k]<="N":
                hour=hourDict[str1[k]]
                break
    for j in range(0,min(len(str3),len(str4))):
        if str3[j]==str4[j] and ("A"<=str3[j]<="Z" or "a"<=str3[j]<="z"):
            if j<10:
                second="0"+str(j)
            else:
                second=str(j)
            break
    return [date,hour,second]

def main():
    str1=input()
    str2=input()
    str3=input()
    str4=input()
    alist=decodeString(str1,str2,str3,str4)
    print(alist[0]+" "+alist[1]+":"+alist[2])

if __name__ == '__main__':
    main()

