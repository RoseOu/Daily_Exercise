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

int SqSearch(SSTable ST, KeyType kval){
    int i;
    ST.elem[0].key=kval;
    for(i=ST.length;ST.elem[i].key!=kval;--i);
    return i;
}

int main(){
    int arr[5]={1,2,3,4,5};
    SSTable ST;
    ST.elem=new ElemType [5];
    ST.length=5;
    for(int i=1;i<ST.length+1;i++){
        ST.elem[i].key=arr[i-1];
    }
    cout<<SqSearch(ST,3);
    return 0;
}
