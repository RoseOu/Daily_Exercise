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

int InsertionSearch(SSTable ST, KeyType kval, int low, int high)
{
    int mid = low+((kval-ST.elem[low].key)*(ST.elem[high].key-ST.elem[low].key)/(ST.elem[high].key-ST.elem[low].key));
    if(ST.elem[mid].key>kval){
        return InsertionSearch(ST, kval, low, mid-1);
    }else if(ST.elem[mid].key<kval){
        return InsertionSearch(ST, kval, mid+1, high);
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
    cout<<InsertionSearch(ST,3,1,ST.length);
    return 0;
}