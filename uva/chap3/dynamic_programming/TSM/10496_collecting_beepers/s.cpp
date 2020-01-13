#include <iostream>
using namespace std;


//AC
#define FOR(i,n) for(int i =0 ; i < (int)n; ++i)
const int N = 20;
const int B = 10;
const int INF = 2*N*(B+1) +100;
int dist[N][N], x[N], y[N], sx, sy, dp[B][1<<B],T,n,m,b,ans;
int tsp(int i, int bm){
    if(bm == (1<<b)-1) return abs(sx - x[i]) + abs(sy-y[i]);
    if(dp[i][bm] != -1) return dp[i][bm];
    int res = INF;
    FOR(j, b){
        if(!(bm & (1<<j))) res = min(res, dist[i][j] + tsp(j, bm | (1<<j)));
    }
    return dp[i][bm] = res;
}
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d %d", &n, &m);
        scanf("%d %d", &sx, &sy);
        scanf("%d", &b);
        FOR(i,b) {
            scanf("%d %d", &x[i], &y[i]);
            dist[i][i] = 0;
            FOR(j, i) dist[i][j] = dist[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        }
        ans = INF;
        FOR(i,b){
            FOR(i,b) FOR(j, 1<<b) dp[i][j] = -1;
            ans = min(ans, abs(sx - x[i]) + abs(sy-y[i]) + tsp(i, 1<<i));
        }
        printf("The shortest path has length %d\n", ans);
    }
}