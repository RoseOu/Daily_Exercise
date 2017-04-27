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

int BinarySearch(SSTable ST, KeyType kval, int low, int high)
{
    int mid = low+(high-low)/2;
    if(ST.elem[mid].key>kval){
        return BinarySearch(ST, kval, low, mid-1);
    }else if(ST.elem[mid].key<kval){
        return BinarySearch(ST, kval, mid+1, high);
    }else{
        return mid;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    SSTable ST;
    ST.elem=new ElemType [6];
    ST.length=5;
    for(int i=1;i<ST.length+1;i++){
        ST.elem[i].key=arr[i-1];
    }
    cout<<BinarySearch(ST,4,1,ST.length);
    return 0;
}