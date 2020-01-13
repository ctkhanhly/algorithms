#include <iostream>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 75;
int T, n,g[N+5][N+5], elem,mx,r,c;
int main(){
    scanf("%d", &T);
    FOR(t,T){
        scanf("%d", &n);
        FOR(er,n) FOR(ec,n) {
            scanf("%d", &g[er][ec]);
            if(er == 0 && ec == 0) mx = g[er][ec];
            if(er) g[er][ec] += g[er-1][ec];
            if(ec) g[er][ec] += g[er][ec-1];
            if(er && ec) g[er][ec] -= g[er-1][ec-1];
        }
        //same run time
        FOR(sr, n) FOR(sc, n)
        for(int er = sr; er < sr+n; ++er) for(int ec = sc; ec < sc+n; ++ec){
                r = min(er, n-1), c = min(ec,n-1);
                elem = g[r][c];
                if(sr) elem -= g[sr-1][c];
                if(sc) elem -= g[r][sc-1];
                if(sr && sc) elem += g[sr-1][sc-1];
                if(er >= n){
                    elem += g[er-n][c];
                    if(sc) elem -= g[er-n][sc-1];
                }
                if(ec >= n){
                    elem += g[r][ec-n];
                    if(sr) elem -= g[sr-1][ec-n];
                }
                if(er >= n && ec >= n){
                    elem += g[er-n][ec-n];
                }
                mx = max(mx, elem);
            }
        cout << mx << endl;
    }
}