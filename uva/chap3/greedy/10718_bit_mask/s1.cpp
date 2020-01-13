#include <iostream>
using namespace std;

//AC
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
uint32_t N, L, U, M;
int main(){
    while(scanf("%d %d %d", &N, &L, &U)==3){
        M = 0;
        for(int i = 31; i >= 0; --i){
            if( N & (1<<i) ){
                if(M + (1<<i)-1 < L) M |= (1<<i);
            }
            else{
                if(M + (1<<i) <= U) M |= (1<<i);
            }
        }
        cout << M << endl;
    }
}