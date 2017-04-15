#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct{
    KeyType key;
} ElemType;

typedef struct{
    ElemType *elem;
    int length;
} SSTable;

int SqSearch(SSTable ST, KeyType kval){ //kval为需要查找的给定值
    for(int i=1;i<ST.length+1;i++){  //依次和给定值进行比较
        if (ST.elem[i].key==kval){  //若某个元素的关键字与给定值相等，则查找成功
            return i;    //返回数据元素所在的顺序
        }
    }
    return 0;   //直到扫描结束仍然没有数据元素的关键字与给定值相等，查找失败，返回0
}

int main(){
    int arr[5]={1,2,3,4,5};
    SSTable ST;
    ST.elem=new ElemType [6];
    ST.length=5;
    for(int i=1;i<ST.length+1;i++){
        ST.elem[i].key=arr[i-1];
    }
    cout<<SqSearch(ST,3);
    return 0;
}
