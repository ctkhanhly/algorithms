#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


//AC
const int N = 200;
const int M = 10;
const int D = 20;
typedef vector<int> vi;
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,Q,d,m, nums[N+5],num,t;
ll res, dp[N+5][M+5][D+5];

ll backtrack(int i, int cm, int sum){
    if(i == n) return cm == m && (sum%d == 0);
    if(cm == m ) return sum %d == 0;
    if(dp[i][cm][sum] != -1) return dp[i][cm][sum];
    ll ans = 0;
    for(int j = i; j <= n-(m-cm); ++j){
        ans += backtrack(j+1, cm+1, ( ((sum + nums[j]) %d) + d) %d);
    }
    return dp[i][cm][sum] = ans;
}
int main(){
    t = 1;
    while(scanf("%d %d", &n, &Q), n || Q){
        FOR(i,n) scanf("%d",&nums[i]);
        
        //size and sum, 2^32*200
        printf("SET %d:\n", t);
        FOR(q,Q){
            scanf("%d %d", &d, &m);
            FOR(i, n) FOR(j, m+1) FOR(k, d) dp[i][j][k] =  -1;
            res = backtrack(0, 0, 0);
            // FOR(i, n) FOR(j, m+1) FOR(k, d) if(j ==m) cout << dp[i][j][k] << endl;
            printf("QUERY %d: %lld\n", q+1, res);
        }
        ++t;
    }
}
/*
SET 1:
QUERY 1: 2
QUERY 2: 9
SET 2:
QUERY 1: 1
*/