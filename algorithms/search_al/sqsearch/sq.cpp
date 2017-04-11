#include <iostream>
using namespace std;

int SequenceSearch(int *elem, int num, int n){
    for(int i=0;i<n;i++){
        if (elem[i]==num){
            return i;
        }
    }
    return -1;
}

int main(){
    int elem[5]={1,2,3,4,5};
    cout<<SequenceSearch(elem,3,5);

    return 0;
}


