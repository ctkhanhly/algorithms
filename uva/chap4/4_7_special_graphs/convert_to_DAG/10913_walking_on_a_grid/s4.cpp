#include <iostream>
#include <limits.h>
using namespace std;


//AC :)
#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
const int N = 75;
const int K = 5;
const int INF = INT_MIN;
int n, m, dp[80][10][2], dp2[80][10][2], g[80][80],res,z,last1, last2,last;

void goLeft(int r, int k){
    for(int c = n-1; c >= 1; --c){
        if(dp2[c+1][k][0] == INF) continue;
        if(g[r][c] >= 0){
            dp2[c][k][0] = max(dp2[c][k][0], g[r][c] + dp2[c+1][k][0]);
        }
        else if(g[r][c] < 0){
            dp2[c][k+1][0] = max(dp2[c][k+1][0], g[r][c] + dp2[c+1][k][0]);
        }
    }
}
void goRight(int r, int k, int c1){
    for(int c = c1; c <= n; ++c){
        if(dp2[c-1][k][1] == INF) continue;
        if(g[r][c] >= 0){
            dp2[c][k][1] = max(dp2[c][k][1], g[r][c] + dp2[c-1][k][1]);
        }
        else if(g[r][c] < 0){
            dp2[c][k+1][1] = max(dp2[c][k+1][1], g[r][c] + dp2[c-1][k][1]);
        }
    }
    if(r == n) res = max(res, dp2[n][k][1]);
}
void goDown(int r){
    for(int c= 1; c <= n; ++c) FOR(k,m+1) {
        last = max(dp[c][k][0], dp[c][k][1]);
        if(last == INF) continue;
        if(g[r][c] >= 0)
            dp2[c][k][0] = dp2[c][k][1] = last + g[r][c];
        else if(g[r][c] < 0){
            dp2[c][k+1][0] = dp2[c][k+1][1] = last + g[r][c];
        }
            
    }
}
void printDEBUG(){
    FOR(j,n+1) {FOR(k, m+1) cout << dp2[j][k][0] << ' '; cout << endl;}
    cout << endl;
    FOR(j,n+1) {FOR(k, m+1) cout << dp2[j][k][1] << ' '; cout << endl;}
    cout << endl;
}
int main(){
    z = 1;
    while(scanf("%d %d", &n, &m), n|| m){
        FOR(i,n)FOR(j,n) scanf("%d", g[i+1]+j+1);
        FOR(i,n+1) FOR(j,m+1) dp[i][j][0] = dp[i][j][1] = 0, dp2[i][j][0] = dp2[i][j][1] = INF;
        res = INF;
        dp2[0][0][1] = 0;
        FOR(k,m+1) goRight(1,k,1);
        for(int r = 2; r <= n; ++r){
            FOR(i,n+1) FOR(j,m+1) dp[i][j][0] = dp2[i][j][0], dp[i][j][1] = dp2[i][j][1], dp2[i][j][0] = dp2[i][j][1] = INF;
            goDown(r);
            FOR(k, m+1){
                goLeft(r,k);
                goRight(r,k,2);
            }
        }
        
        printf("Case %d: ",z);
        if(res != INF) printf("%d\n", res);
        else printf("impossible\n");
        ++z;
    }
}