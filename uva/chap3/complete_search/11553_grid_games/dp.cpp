#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 8;
const int INF = 8001;
int t,n, g[N][N], dp[(1<<N)][(1<<N)], full;
//Alice can have 2^8 choices, so as Bob
int solve(int maskA, int maskB){
    // cout << maskA << ' ' << maskB << endl;
    if(maskA == full && maskB == full) return 0;
    if(dp[maskA][maskB] != INF) return dp[maskA][maskB];
    int mx = -INF;
    FOR(i,n){
        if(maskA & (1<<i))continue;
        int mn =  INF;
        FOR(j,n){
            //B chooses min option
            if(maskB & ( 1 << j)) continue;
            mn = min(mn, g[i][j] + solve(maskA|(1<<i), maskB|(1<<j)));
        }
        //A chooses max option
        mx = max(mx, mn);
    }
    return dp[maskA][maskB] = mx;
}
int main(){
    scanf("%d",&t);
    FOR(z,t){
        scanf("%d",&n);
        FOR(i,n) FOR(j,n) scanf("%d", &g[i][j]);
        full = (1<<n) - 1;
        FOR(i, 1<<n) fill(dp[i], dp[i] + (1<<n), INF);
        cout << solve(0,0) << endl;
    }
}