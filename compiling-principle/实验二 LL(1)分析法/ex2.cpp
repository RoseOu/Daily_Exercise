#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#define MAX 500

using namespace std;

//大写字母为非终止符(可以多一个'的标号做区分)，小写字母为终止符,用~代替epsilon
class Rule{
    public:
        string left;
        set<string> right;
        Rule ( string s){
            left = s;
        }
        void print(){
            cout<<left+"->";
            set<string>::iterator it = right.begin();
            if ( right.begin()!= right.end() ){
                cout<<*it;
                it++;
            }
            for(; it != right.end() ; it++ )
                cout<<"|"+*it;
            cout<<endl;
        }
        void insert(string s){
            right.insert(s);
        }
};

map<string,set<char> > first;  //所有非终结符的first集
map<string,set<char> > follow;  //所有非终结符的follow集
map<string,int> VN_dic; //（规则左部，规则顺序）
vector<Rule> grammar;  //文法所有规则
vector<map<char,string> > predict_table;  //预测分析表
vector<char> letter;    //终结符
bool used[MAX];

void make_first (int x){
    if ( used[x] ) return;    //如果该非终结符的first集已经求过就不再求了，直接返回
    used[x] = 1;
    string left = grammar[x].left;  //第x条规则的左部
    set<string> right = grammar[x].right;    //第x条规则的右部
    set<string>::iterator it;
    for (it = right.begin(); it!= right.end() ; it++ ){   //遍历规则右部(xx|xx|xx)
        for ( int i = 0 ; i < it->length() ; i++ ){   //遍历某一个右部的符号串(xx)
            if ( !isupper( it->at(i) ) && it->at(i) != '\'' ){  //若当前符号不是大写字母且不是'（即为终结符号）
                first[left].insert ( it->at(i) );   //将符号加入first集，break
                break;
            }
            if ( isupper( it->at(i) ) ){   //若当前符号是大写字母
                int y;
                if ( i != it->length()-1 && it->at(i+1) == '\'' ){  //若当前符号是规则的倒数第2个符号且下一个符号是'(E')
                    y = VN_dic[it->substr(i,2)]-1;  //y为该符号属于的规则左部的规则顺序
                }else{                  //若当前符号是规则的最后一个符号(E)
                    y = VN_dic[it->substr(i,1)]-1;  //y为该符号属于的规则左部的规则顺序
                }
                string& tleft = grammar[y].left;    //tleft为该符号（即该规则左部）
                make_first ( y );  //再求该非终结符的first集
                set<char> temp = first[tleft];  //temp为该非终结符的first集
                set<char>::iterator it1;
                bool flag = true;
                for (it1 = temp.begin(); it1 != temp.end(); it1++ ){  //遍历该非终结符的first集
                    if ( *it1 == '~' ){   //如果有空串
                        flag = false;
                    }
                    first[left].insert( *it1 );  //将该非终结符的first集加入要求的非终结符的first集
                }
                if ( flag ) break;  //如果该终结符的first集没有空串，就不用再往下遍历了
            }
            else continue;  //若符号是’则跳过
        }
    }
}

void all_first ( ){
    memset(used , 0 , sizeof(used));   //将used全部赋值为0
    for(int i = 0 ; i < grammar.size() ; i++ ){  //遍历规则，第i条规则
        make_first ( i );
    }
}

//将str1的follow集加到str2的follow集里
void append ( const string& str1 , const string& str2 ) {
    set<char>& from = follow[str1];
    set<char>& to = follow[str2];
    set<char>::iterator it;
    for (it = from.begin(); it != from.end() ; it++){
        to.insert ( *it );
    }
}

void all_follow ( ){
    while ( true ){
        bool goon = false;
        for ( int i = 0 ; i < grammar.size() ; i++ ){  //遍历文法里的规则
            string left = grammar[i].left;    //left为规则左部
            set<string> right = grammar[i].right;  //right为所有规则右部
            set<string>::iterator it;
            for (it = right.begin(); it!= right.end() ; it++ ){   //遍历规则右部
                bool flag = true;
                const string& str = *it;
                for ( int j = it->length()-1 ; j >= 0 ; j-- ){   //从后向前遍历某一个右部的符号串
                    if ( str[j] == '\'' ){    //若当前符号为'（即为非终结符号且有'）
                        int x = VN_dic[it->substr(j-1,2)]-1;  //x为该符号属于的规则左部的规则顺序
                        if(x==0){
                            set<char> &now = follow[it->substr(j-1,2)];
                            now.insert('$');
                        }
                        if ( flag ) {
                            int tt = follow[it->substr(j-1,2)].size();  //tt为该符号的原follow集大小
                            append ( left , it->substr(j-1,2) );  //将left的follow集加到该符号的follow集里
                            int tt1 = follow[it->substr(j-1,2)].size(); //tt1为该符号的现follow集大小
                            if ( tt1 > tt ){
                                goon = true;
                            }
                            if ( !grammar[x].right.count("~" ) ){  //如果该非终结符不会推导出空串
                                flag = false;
                            }
                        }
                        for ( int k = j+1 ; k < it->length() ; k++ ){  //遍历该符号后面的符号
                            if ( isupper(str[k]) ){   //若有非终结符
                                string id;
                                if ( k != it->length()-1 && str[k+1] == '\'' ){  //id为该符号后面的非终结符
                                    id = it->substr(k,2);
                                }else{
                                    id = it->substr(k,1);
                                }
                                set<char>& from = first[id];
                                set<char>& to = follow[it->substr(j-1,2)];
                                int tt = to.size();
                                set<char>::iterator it1;
                                for (it1 = from.begin(); it1 != from.end() ; it1++){ //将非终结符id的first集加到该符号的follow集
                                    if ( *it1 != '~' ){
                                        to.insert ( *it1 );
                                    }
                                }
                                int tt1 = follow[it->substr(j-1,2)].size();
                                if ( tt1 > tt ){
                                    goon = true;
                                }
                                if ( !grammar[VN_dic[id]-1].right.count("~") ){  //若id不可推导出空串
                                    break;
                                }
                            } else if( str[k] != '\'' ){  //若有终结符
                                int tt = follow[it->substr(j-1,2)].size();
                                follow[it->substr(j-1,2)].insert ( str[k] );  //则将其终结符加到follow集里
                                int tt1 = follow[it->substr(j-1,2)].size();
                                if ( tt1 > tt ){
                                    goon = true;
                                }
                                break;  //且不需要再遍历后面的符号
                            }else{   //若是符号'，则跳过
                                continue;
                            }
                        }
                        j--;    //用以跳过符号'
                    } else if ( isupper(str[j] ) ){    //若当前符号为非终结符号
                        int x = VN_dic[it->substr(j,1)]-1;
                        if(x==0){
                            set<char> &now = follow[it->substr(j,1)];
                            now.insert('$');
                        }
                        if ( flag ){
                            int tt = follow[it->substr(j,1)].size();
                            append ( left , it->substr(j,1) );
                            if ( !grammar[x].right.count("~") ){
                                flag = false;
                            }
                            int tt1 = follow[it->substr(j,1)].size();
                            if ( tt1 > tt ){
                                goon = true;
                            }
                        }
                        for ( int k = j+1 ; k < it->length() ; k++ ){
                            if ( isupper( str[k] ) ){
                                string id;
                                if ( k != it->length()-1 && str[k+1] == '\'' ){
                                    id = it->substr(k,2);
                                }
                                else {
                                    id = it->substr(k,1);
                                }
                                set<char>& from = first[id];
                                set<char>& to = follow[it->substr(j,1)];
                                set<char>::iterator it1 = from.begin();
                                int tt = follow[it->substr(j,1)].size();
                                for ( ; it1 != from.end() ; it1++ ){
                                    if ( *it1 != '~' )
                                        to.insert( *it1 );
                                }
                                int tt1 = follow[it->substr(j,1)].size();
                                if ( tt1 > tt ){
                                    goon = true;
                                }
                                if ( !grammar[VN_dic[id]-1].right.count("~") ){
                                    break;
                                }
                            }
                            else if ( str[k] != '\'' ){
                                int tt = follow[it->substr(j,1)].size();
                                follow[it->substr(j,1)].insert ( str[k] );
                                int tt1 = follow[it->substr(j,1)].size();
                                if ( tt1 > tt ){
                                    goon = true;
                                }
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                    }else{
                        flag = false;
                    }
                }
            }
        }
        if (!goon){
            break;
        }
    }
}

//检查一个字符是否属于一个字符串的FIRST集合
bool check_first ( const string& text , char ch ){
    for ( int i = 0 ; i < text.length() ; i++ ){
        bool hasEmpty = false;
        if ( !isupper(text[i]) && text[i] != '\'' ){
            if ( text[i] != ch ) return false;
            else return true;
        }else if ( isupper(text[i] ) ){
            string temp;
            if ( i != text.length()-1 && text[i+1] == '\'' ){
                temp = text.substr(i,2);
            }else{
                temp = text.substr(i,1);
            }
            set<char> dic = first[temp];
            set<char>::iterator it;
            for (it = dic.begin(); it != dic.end() ; it++){
                if( *it == '~' ){
                    hasEmpty = true;
                }
                if( *it == ch ){
                    return true;
                }
            }
            if( !hasEmpty){
                break;
            }
        }else{
            continue;
        }
    }
    return false;
}

//检查一个字符ch是否属于一个字符串text的FOLLOW集合
bool check_follow ( const string& text , char ch ){
    set<char> dic = follow[text];
    set<char>::iterator it;
    for (it = dic.begin(); it != dic.end() ; it++ ){
        if ( *it == ch ){
            return true;
        }
    }
    return false;
}

void make_table (){
    map<char,string> temp;  //用来存放分析表的每一行
    bool vis[MAX];
    memset ( vis , 0 , sizeof ( vis ) );
    for ( int i = 0 ; i < grammar.size() ; i++ ){  //遍历文法的每一条规则
        set<string> right = grammar[i].right;
        set<string>::iterator it;
        for (it = right.begin(); it != right.end() ; it++){   //遍历规则右部
            for ( int j = 0 ; j < it->length() ; j++ ){  //遍历某一右部的字符串
                if ( !isupper(it->at(j)) && it->at(j) != '\'' ){  //如果是终结符
                    if ( vis[it->at(j)] ){   //且没有出现过
                        continue;
                    }
                    vis[it->at(j)] = true;
                    letter.push_back ( it->at(j) );  //则加入letter
                }
            }
        }
    }
    letter.push_back('$');

    for ( int i = 0 ; i < grammar.size() ; i++ ){    //遍历文法的每一条规则
        temp.clear();  //清空temp
        string left = grammar[i].left;   //left为规则左部
        set<string> right = grammar[i].right;  //right为规则右部
        set<string>::iterator it;
        for (it = right.begin(); it != right.end() ; it++){  //遍历规则右部
            for (int j = 0 ; j < letter.size() ; j++){     //遍历所有终结符
                if ( check_first ( *it , letter[j] ) ){   //若终结符属于该规则右部的first集
                    temp[letter[j]] = *it;
                }
                if ( it->at(0) == '~' && check_follow ( left, letter[j] ))  //若该规则右部可推导出空串，且终结符属于该规则左部的follow集
                    temp[letter[j]] = *it;
            }
        }
        predict_table.push_back ( temp );
    }
}

void print ( int steps , stack<string> stk , string src , string tmp , int idx ){
    cout<<left<<setw(10)<<steps;
    string out = "";
    while ( !stk.empty() ){
        out = stk.top()+out;
        stk.pop();
    }
    cout<<"$"<<left<<setw(9)<<(out.c_str());
    out ="";
    for (int i = idx; i < src.length(); i++){
        out += src[i];
    }
    cout<<left<<setw(10)<<(out.c_str());
    cout<<left<<setw(10)<<(tmp.c_str())<<endl;
}

void analyse ( const string& src ){
    stack<string> stk;  //分析栈
    map<string,int>::iterator vndic_it;
    for(vndic_it=VN_dic.begin();vndic_it!=VN_dic.end();vndic_it++){
        if(vndic_it->second == 1){
            break;
        }
    }
    stk.push ( vndic_it->first.c_str() );  //将文法开始符号推进分析栈
    int steps = 0;   //步骤
    int idx = 0;    //
    cout<<left<<setw(12)<<"步骤"<<left<<setw(13)<<"分析栈"<<left<<setw(12)<<"输入串"<<left<<setw(10)<<"所用规则"<<endl;
    string u = stk.top();  //取分析栈栈顶符号
    string tmp=""; 
    print ( steps++ , stk , src , tmp  , idx );
    while ( !stk.empty() ){
        string u = stk.top();  //取分析栈栈顶符号
        string tmp=""; 
        stk.pop();
        if ( !isupper(u[0]) ) { //若栈顶符号为终结符号
            if ( idx == src.length() && u[0] == '~' );
            else if (src[idx] == u[0]){  //输入串第idx个符号=若栈顶符号
                idx++;
            }
        } else {   //否则
            int x = VN_dic[u]-1;  
            tmp = predict_table[x][src[idx]];  //所用规则的规则右部
            if(tmp!="~"){
                for ( int i = tmp.length()-1 ; i >= 0 ; i-- ){  //将其逆序入栈
                    if ( tmp[i] == '\'' ){
                        string v = tmp.substr(i-1,2);
                        stk.push ( v );
                        i--;
                    }else{
                        string v = tmp.substr(i,1);
                        stk.push( v );
                    }
                }
            }
            tmp = u+"->"+tmp;
        }
        print (steps++, stk, src, tmp, idx);
    }
    cout<<endl;

    if(stk.empty() && src.substr(idx)=="$"){
        cout<<"分析成功，该字符串是该文法的句型。"<<endl;
    }else{
        cout<<"分析失败，该字符串不是该文法的句型。"<<endl;
    }
}


int main ( ){
    int n;
    string s,l,r;
    cout<<"*********** 输入规则的条数 ***********"<<endl;
    cin>>n;
    cout<<endl;

    cout<<"*********** 输入全部规则（注意：对于左部相同的规则需要分开写） ***********"<<endl;
    cout<<"（注意：1. 对于左部相同的规则必须分开写。2. 大写字母为非终结符，可以多一个 ' 的标号做区分；小写字母为终结符，用 ~ 代替epsilon。）"<<endl;
    for ( int i = 0 ; i < n ; i++ ){   //输入规则
        cin>>s;        //输入一条规则
        int len = s.length(),j;    //len为规则字符串长度，
        for ( j = 0 ; j < len ; j++ ){  //检测到‘-’时，break，j为‘-’的位置
            if ( s[j] == '-' ) break;
        }
        l.assign(s, 0, j);   //s为规则左部
        r.assign(s,j+2);
        if ( !VN_dic[l] ){  //若VN_dic中没有s，
            Rule rule(l);      //建立一个规则，s作为规则的左部
            grammar.push_back(rule);   //将规则加入grammar
            VN_dic[l] = grammar.size();   //（规则左部，规则顺序）
        }
        int x = VN_dic[l]-1;   
        grammar[x].insert(r);  //插入规则右部
    }
    cout<<endl;

    cout<<"*********** 文法 ***********"<<endl;
    vector<Rule>::iterator itv;
    for(itv=grammar.begin();itv!=grammar.end();itv++){
        itv->print();
    }
    cout<<endl;

    all_first();
    cout<<"*********** FIRST集 ***********"<<endl;
    map<string,set<char> >::iterator it;
    for (it = first.begin(); it != first.end() ; it++ ){
        cout<<"FIRST("<<(it->first.c_str())<<")={";
        set<char> temp = it->second;
        set<char>::iterator it1 = temp.begin();
        bool flag = false;
        for ( ; it1 != temp.end() ; it1++ ){
            if ( flag ){
                cout<<",";
            }
            cout<<*it1;
            flag = true;
        }
        cout<<"}"<<endl;
    }
    cout<<endl;

    all_follow();
    cout<<"*********** FOLLOW集 ***********"<<endl;
    for (it = follow.begin(); it != follow.end() ; it++){
        cout<<"FOLLOW("<<it->first.c_str()<<")={";
        set<char> temp = it->second;
        set<char>::iterator it1;
        bool flag = false;
        for (it1 = temp.begin(); it1 != temp.end() ; it1++){
            if ( flag ){
                cout<<",";
            }
            cout<<*it1;
            flag = true;
        }
        cout<<"}"<<endl;
    }
    cout<<endl;

    make_table();
    cout<<"*********** 预测分析表 ***********"<<endl;
    for ( int i = 0 ; i <= (letter.size()+1)*16 ; i++ ){
        cout<<"-";
    }
    cout<<endl;
    cout<<"|"<<setw(15)<<"|";
    for ( int i = 0 ; i < letter.size() ; i++ ){
        cout<<setw(8)<<letter[i]<<setw(8)<<"|";
    }
    cout<<endl;
    for ( int i = 0 ; i <= (letter.size()+1)*16 ; i++ ){
        cout<<"-";
    }
    cout<<endl;
    for ( int i = 0 ; i < grammar.size() ; i++ ){
        cout<<"|"<<setw(8)<<(grammar[i].left.c_str())<<setw(7)<<"|";
        for ( int j = 0 ; j < letter.size() ; j ++ ){
            if ( predict_table[i].count(letter[j] ) ){
                cout<<right<<setw(4)<<(grammar[i].left.c_str())<<setw(2)<<"->";
                cout<<left<<setw(6)<<(predict_table[i][letter[j]].c_str());
                cout<<right<<setw(4)<<"|";
            }else{
                cout<<setw(16)<<"|";
            }
        }
        cout<<endl;
        for ( int i = 0 ; i <= (letter.size()+1)*16 ; i++ ){
            cout<<"-";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"*********** 输入要分析的字符串 ***********"<<endl;
    string in;
    cin>>in;
    cout<<endl;

    cout<<"*********** 对输入串"<<in<<"的分析过程 ***********"<<endl;
    analyse( (in+"$") );
    cout<<endl;
}