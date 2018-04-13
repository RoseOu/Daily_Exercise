#include <iostream>
#include <stdio.h>
#include <string.h>
#define _KEY_WORD_END "waiting for your expanding"   //定义关键字结束标志
using namespace std;

typedef struct{    //单词二元组
    int typenum;
    char * word;
}Word;

char ch;                //当前读入字符
char input[255];        //输入缓冲区
char token[255] = "";   //单词换缓冲区
int p_input;            //输入换缓冲区指针
int p_token;            //单词缓冲区指针
char* rwtab[] = {"if","else","while","int","return",_KEY_WORD_END};  //关键字数组

Word* scaner();   //词法扫描函数，获得一个单词
void retract();
char m_getch();
void getbc();
void concat();
int letter();
int digit();
int reserve();

int main(){
    int over = 1;
    Word* oneword = new Word;
    cout<<"----- 输入你的源程序(以#结尾) -----"<<endl;
    scanf("%[^#]s",input);          //读入源程序字符串到缓冲区，以#结束，允许多行输入
    p_input = 0;
    cout<<"----- 你的源程序 -----"<<endl;
    cout<<input<<endl;
    cout<<"----- 输出单词二元组（单词种别，单词自身的值） -----"<<endl;
    while(over < 1000 && over != -1){    //对源程序进行分析，直至结束符#
        oneword = scaner();              //获得一个新单词
        if(oneword->typenum < 1000){
            cout<<"("<<oneword->typenum<<","<<oneword->word<<")"<<endl;   //打印种别码和单词自身值
        }
        over = oneword->typenum;
    }
    return 0;
}

//从输入缓冲区读取一个字符到ch中
char m_getch(){
    ch = input[p_input];
    p_input++;
    return (ch);
}

//去掉空白符号
void getbc(){
    while(ch == ' ' || ch == 10){
        ch = input[p_input];
        p_input++;
    }
}

//拼接单词
void concat(){
    token[p_token] = ch;
    p_token++;
    token[p_token] = '\0';
}

//判断是否字母
int letter(){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        return 1;
    else
        return 0;
}

//判断是否是数字
int digit(){
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

//检查关键字表格
int reserve(){
    int i = 0;
    while(strcmp(rwtab[i],_KEY_WORD_END)){
        if(!strcmp(rwtab[i],token)){
            return i+1;
        }
        i++;
    }
    return 10;
}

//回退一个字符
void retract(){
    p_input--;
}

//数字转换成二进制
char* dtb(int token){
    char *str;
    return NULL;
}

Word* scaner(){
    Word* myword = new Word;
    myword->typenum = 10;
    myword->word = "";
    p_token = 0;
    m_getch();
    getbc();
    if(letter()){
        while(letter() || digit()){
            concat();
            m_getch();
        }
        retract();
        myword->typenum = reserve();
        myword->word = token;
        return(myword);
    }else if(digit()){
        while(digit()){
            concat();
            m_getch();
        }
        retract();
        myword->typenum = 20;
        myword->word = token;
        return(myword);
    }
    else switch(ch){
        case '=':
            m_getch();
            if(ch == '='){
                myword->typenum = 39;
                myword->word = "==";
                return(myword);
            }
            retract();
            myword->word = "=";
            myword->typenum = 21;
            return(myword);
            break;
        case '+':
            myword->typenum = 22;
            myword->word = "+";
            return(myword);
            break;
        case '-':
            myword->typenum = 23;
            myword->word = "-";
            return(myword);
            break;
        case '*':
            myword->typenum = 24;
            myword->word = "*";
            return(myword);
            break;
        case '/':
            myword->typenum = 25;
            myword->word = "/";
            return(myword);
            break;
        case '(':
            myword->typenum = 26;
            myword->word = "(";
            return(myword);
            break;
        case ')':
            myword->typenum = 27;
            myword->word = ")";
            return(myword);
            break;
        case '[':
            myword->typenum = 28;
            myword->word = "[";
            return(myword);
            break;
        case ']':
            myword->word = "]";
            myword->typenum = 29;
            return(myword);
            break;
        case '{':
            myword->typenum = 30;
            myword->word = "{";
            return(myword);
            break;
        case '}':
            myword->typenum = 31;
            myword->word = "}";
            return(myword);
            break;
        case ',':
            myword->typenum = 32;
            myword->word = ",";
            return(myword);
            break;
        case ':':
            myword->word = ":";
            myword->typenum = 33;
            return(myword);
            break;
        case ';':
            myword->typenum = 34;
            myword->word = ";";
            return(myword);
            break;
        case '>':
            m_getch();
            if(ch == '='){
                myword->word = ">=";
                myword->typenum = 37;
                return(myword);
            }
            retract();
            myword->typenum = 35;
            myword->word = ">";
            return(myword);
            break;
        case '<':
            m_getch();
            if(ch == '='){
                myword->word = "<=";
                myword->typenum = 38;
                return(myword);
            }
            retract();
            myword->typenum = 36;
            myword->word = "<";
            return(myword);
            break;
        case '!':
            m_getch();
            if(ch == '='){
                myword->word = "!=";
                myword->typenum = 40;
                return(myword);
            }
            retract();
            myword->typenum = -1;
            myword->word = "ERROR";
            return(myword);
            break;
        case '\0':
            myword->typenum = 1000;
            myword->word = "OVER";
            return(myword);
            break;
        default:
            myword->typenum = -1;
            myword->word = "Error";
            return(myword);
            break;
    }
}

