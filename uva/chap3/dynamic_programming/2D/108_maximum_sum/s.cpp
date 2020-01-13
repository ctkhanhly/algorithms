#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
int g[N+2][N+2],currSum, mx, n, elem;
int main(){
    while(scanf("%d", &n)==1){
        FOR(er, n) {
            currSum = 0;
            FOR(ec, n){
                scanf("%d", &g[er][ec]);
                if(er) g[er][ec] += g[er-1][ec];
                
            }
        }
        mx = g[0][0];
        FOR(er,n) FOR(sr, er+1) {
            currSum = 0;
            FOR(ec,n){
                elem = g[er][ec];
                if(sr) elem -= g[sr-1][ec];
                currSum = max(currSum + elem, elem);
                mx = max(mx, currSum);
            }
        }
        cout << mx << endl;
    }
    
        
}