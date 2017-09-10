#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define NUM 10004
vector <int> primes(NUM);

void findPrimes(){
    
    //如果不能被任何一个质数整除，那就是质数
    int cnt=0;// 第cnt个质数，从1开始计数
    int a = 2;// 从2开始的自然数 a
    while (cnt <= NUM) {
        // 优化1：排除偶数
        if (a % 2 == 0 && a != 2) {
            ++a;
            continue;
        }

        int i = 0;
        // 优化2：不超过第cnt个质数的开方数
        for (i = 0; i < sqrt(cnt); ++i) {
            if (a % primes[i] == 0) {
                break;
            }
        }
        if (i >= sqrt(cnt)) {
            primes[cnt] = a;
            cnt++;

        }
        ++a;
    }
    
}
int main(){
    
    // 预处理
    findPrimes();
    
    // 输入数据
    int m,n;
    cin >> m >> n;
    
    // 按格式输出
    for(int i = m; i <= n; ++i){
        
        cout << primes[i-1];
        
        if ((i-m+1) % 10 == 0 || i == n) {
//          cout << endl;
            printf("\n");
        }else{
//          cout << ' ';
            printf(" ");
        }
        
    }
}
