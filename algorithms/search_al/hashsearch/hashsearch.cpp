#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct{
    KeyType key;
} ElemType;

typedef struct{
	ElemType *elem;
	int count;
} HashTable;

const int NULLKEY=0;
const int NUM=11;
const int LENGTH=12;

int Hash(int kval){   //除留余数法
	return kval%NUM;
}

void Next(int &p, int &c){   //线性探测再散列
	p=(p+1)%LENGTH;
}

int HashSearch(HashTable H, KeyType kval,int &p,int &c){
	//在开放定址哈希表H中查找关键码为kval的元素，
	//若查找成功，以p指示待查记录在表中位置,并返回1；否则，以p指示插入位置，并返回0；
	//以c计算冲突次数，其初值置0，供建表插入时参考
	p=Hash(kval);   //求得哈希地址
	while (H.elem[p].key != NULLKEY && (H.elem[p].key != kval)){ //位置中有记录且不等于kval，即有冲突
		Next(p,++c);
	}
	if(H.elem[p].key==kval){
		return p;
	}else{
		return -1;
	}
}

int InsertHash(HashTable &H,ElemType e){
	int c=0,j=0;
	if(HashSearch(H,e.key,j,c)!=-1){
		return -1;
	}else{
		H.elem[j]=e;
		++H.count;
		return 1;
	}
}

int main(){
    ElemType arr[LENGTH-1];
    HashTable H;
    H.elem=new ElemType [LENGTH];
    H.count=0;
    int p=0,c=0;
    for(int j=0;j<LENGTH;j++){
    	H.elem[j].key=NULLKEY;
    }
    for(int k=0;k<LENGTH-1;k++){
    	arr[k].key=k+1;    //记录为1,2,3,4,5,6,7,8,9,10,11
    }
    for(int i=0;i<LENGTH-1;i++){
    	InsertHash(H,arr[i]);
    }
    int a=0,b=0;
    cout<<HashSearch(H,12,a,b);
    return 0;
}
