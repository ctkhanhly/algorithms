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
    FOR(i,n) FOR(j,m) FOR(k,d) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <=n; ++i){
        for(int j = 0; j <=m; ++j){
            for(int k = 0; k < d; ++k){
                dp[i][j][k] += dp[i-1][j][k];//doesn't add this element
                if(j) dp[i][j][(k + (nums[i] %d)+d) % d] += dp[i-1][j-1][k];
            }
        }
    }
    FOR(i,n+1) {
        cout << "i = " << i << endl;
        FOR(j,m+1){
            FOR(k,d) cout << dp[i][j][k] << ' ';
            cout << endl;
        }
        cout << endl;
    }
    return dp[n][m][0];
}

int main(){
    t = 1;
    while(scanf("%d %d", &n, &Q), n || Q){
        FOR(i,n) scanf("%d",&nums[i]), cout << nums[i] << ' ';
        cout << endl;
        
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