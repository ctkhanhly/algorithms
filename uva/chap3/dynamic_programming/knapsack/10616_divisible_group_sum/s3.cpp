#include <iostream>
using namespace std;


const int N = 200;
const int M = 10;
const int D = 20;
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,Q,d,m, nums[N+5],num,t;
ll res, dp[N+5][M+5][D+5];
ll solve(){
    FOR(i,n+1) FOR(j,m+1) FOR(k,d) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    FOR(i,n) FOR(j, min(i+1,m+1)) FOR(k, d){
        dp[i+1][j][k] += dp[i][j][k];
        if(j+1 <= m) dp[i+1][j+1][ ((nums[i]%d) +d+k) % d] += dp[i][j][k];
    }
    return dp[n][m][0];
}

int main(){
    t = 1;
    while(scanf("%d %d", &n, &Q), n || Q){
        FOR(i,n) scanf("%d",&nums[i]);
        
        //size and sum, 2^32*200
        printf("SET %d:\n", t);
        FOR(q,Q){
            scanf("%d %d", &d, &m);
            cout << d << ' ' << m << endl;
            res = solve();
            printf("QUERY %d: %lld\n", q+1, res);
        }
        ++t;
    }
}
/*

i = 1
1 0 0 0 0 0 
0 0 1 0 0 0 
0 0 0 0 0 0 

i = 2
1 0 0 0 0 0 
0 0 1 1 0 0 
0 0 0 1 0 1 

j = 0-> 

d[i+1][j+1][num[i]+k%d] = d[i][j][k]
d[i+1][j][k] += d[i][j][k]

d[2][2][3] += d[1][2][3] (0)
d[2][2][3] += d[1][1][0]

d[2][2][5] += d[1][2][5]
d[2][2][5] += d[1][1][2]
*/