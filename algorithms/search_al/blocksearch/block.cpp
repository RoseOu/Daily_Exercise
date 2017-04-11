#include <iostream>
using namespace std;

typedef int ElemType;

typedef int KeyType;

typedef struct{
    ElemType *elem;
    int length;
} SSTable;

typedef struct{
    KeyType key;
    int stadr;
} indexItem;

typedef struct{
    indexItem *elem;
    int length;
} indexTable;

int Search_Idx(SSTable ST, indexTable ID, KeyType kval){
    int low,high,mid,s,t,k;
    bool found;

    //在顺序表ST中分块查找等于给定值kval的数据元素，ID为索引表
    //若找到，则返回该数据元素在ST中的位置，否则返回0
    low=0;
    high=ID.length-1;
    found=false;
    if(kval>ID.elem[high].key){ //当给定值kval比表中所有数据元素都大
        return 0;
    }
    while(low<=high && !found){ //折半查找索引表，确定查找区间
        mid=(low+high)/2;
        if(kval<ID.elem[mid].key){
            high=mid-1;
        }else if(kval>ID.elem[mid].key){
            low=mid+1;
        }else{
            found=true;low=mid;
        }
    }//while
    s=ID.elem[low].stadr;  //经索引表查找后，下一步的查找范围定位在第low块
    if(low<ID.length-1){
        t=ID.elem[low+1].stadr-1;
    }else{
        t=ST.length;     //s和t为在ST表进行查找的下界和上界
    }
    if(ST.elem[t]==kval){
        return t;
    }else{          //在ST.elem[s]至ST.elem[t-1]的区间内进行顺序查找
        ST.elem[0]=ST.elem[t];   //ST.elem[0]用来暂存ST.elem[t]
        ST.elem[t]=kval;        //设置哨兵
        for(k=s;ST.elem[k]!=kval;k++);
        ST.elem[t]=ST.elem[0];   //回复暂存值
        if(k!=t){
            return k;
        }else{
            return 0;
        }
    }
}

int main(){
    ElemType arr[21]={0,17,8,21,19,31,33,22,25,42,37,40,52,61,78,73,55,94,88,79,85};
    SSTable ST;
    ST.elem=new ElemType [21];
    ST.length=20;
    for(int i=0;i<21;i++){
        ST.elem[i]=arr[i];
    }

    KeyType keyarr[5]={21,33,52,78,94};
    int sta[5]={1,5,9,13,17};
    indexTable ID;
    ID.length=5;
    ID.elem=new indexItem[ID.length];
    for(int i=0;i<ID.length;i++){
        indexItem it;
        it.key=keyarr[i];
        it.stadr=sta[i];
        ID.elem[i]=it;
    }

    int result,kval=31;
    result=Search_Idx(ST,ID,kval);
    cout<<result;

    return 0;
}

