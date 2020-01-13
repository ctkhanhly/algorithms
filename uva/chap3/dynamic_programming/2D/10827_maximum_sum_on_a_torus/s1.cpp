#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 75;
int T, n,g[2*N+5][2*N+5], currSum, elem,mx;
int main(){
    scanf("%d", &T);
    FOR(t,T){
        scanf("%d", &n);
        FOR(er,n) FOR(ec,n) {
            scanf("%d", &g[er][ec]);
            if(er) g[er][ec] += g[er-1][ec];
        }
        FOR(i,n-1) FOR(j, n) g[i+n][j] = g[n-1][j] + g[i][j];
        FOR(j, n-1) FOR(r, 2*n-1) g[r][j+n] = g[r][j];
        mx = g[0][0];
        FOR(sr, n) for(int er = sr; er < sr+n; ++er){
            FOR(sc, n){
                currSum = 0;
                for(int ec = sc; ec < sc+n; ++ec){
                    elem = g[er][ec];
                    if(sr) elem -= g[sr-1][ec];
                    currSum = max(currSum + elem, elem);
                    mx = max(mx, currSum);
                }
            }
        }
        cout << mx << endl;
    }
}