#include <iostream>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
int g[N+5][N+5], currSum, mx, elem,n;
int main(){
    while(scanf("%d", &n)==1){
        FOR(er, n) FOR(ec, n) {
            scanf("%d", &g[er][ec]);
            if(er == 0 && ec == 0) mx = g[er][ec];
            if(er) g[er][ec] += g[er-1][ec];
            if(ec) g[er][ec] += g[er][ec-1];
            if(er && ec) g[er][ec] -= g[er-1][ec-1];
            FOR(sr, er+1) FOR(sc, ec+1){
                elem = g[er][ec];
                if(sr) elem -= g[sr-1][ec];
                if(sc) elem -= g[er][sc-1];
                if(sr && sc) elem += g[sr-1][sc-1];
                mx = max(mx, elem);
            }
        }
        cout << mx << endl;
    }
    
}