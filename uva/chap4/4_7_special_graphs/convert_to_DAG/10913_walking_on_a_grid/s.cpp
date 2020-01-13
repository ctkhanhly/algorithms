#include <iostream>
#include <limits.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 75;
const int INF = INT_MIN;
int n,K,res,z,g[N][N];
int dir[] = {0,1,0,-1};
int dp[5625][10][3];//K =5
bool visited[5625];//5625
int mxSum(int curr, int k, int from){
    int r = curr/n, c = curr%n;
    if(r == n-1 && c == n-1) return g[r][c];
    if(dp[curr][k][from] != INT_MAX) return dp[curr][k][from];
    int ans = INF;
    FOR(p, 3){
        int i = r + dir[p], j = c + dir[p+1];
        if(0 <= i && i < n && 0 <= j && j < n && !visited[n*i+j] ){
            int next;
            if(g[i][j] < 0 && k>0){
                visited[n*i+j] = 1;
                next = mxSum(i*n+j, k-1, p);
                if(next != INF) ans = max(ans, g[r][c] + next);
                visited[n*i+j] = 0;
            } 
            else if(g[i][j] >= 0) {
                visited[n*i+j] = 1;
                next = mxSum(i*n+j,k, p);
                if(next != INF) ans = max(ans, g[r][c] + next);
                visited[n*i+j] = 0;
            }
        }
    }
    return dp[curr][k][from] = ans;
}
int main(){
    z = 1;
    while(scanf("%d %d", &n, &K), n || K){
        FOR(i,n) FOR(j,n) scanf("%d", g[i]+j);
        FOR(i,n*n) { visited[i] = 0; FOR(j, K+1) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INT_MAX;}
        visited[0] = 1;
        if(g[0][0] >= 0) res = mxSum(0, K,0);
        else res = mxSum(0, K-1,0);
        printf("Case %d: ",z);
        if(res != INF) printf("%d\n", res);
        else printf("impossible\n");
        ++z;
    }
}