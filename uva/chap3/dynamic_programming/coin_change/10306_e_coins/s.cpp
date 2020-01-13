#include <iostream>
#include <limits.h>
using namespace std;
 
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
const int M = 40;
const int MONEY = 12000;
int n, m,S, conven[M], ecoin[M];
ll dp[500], dp2[500], res;
int main(){
    scanf("%d", &n);
    FOR(z, n){
        scanf("%d %d", &m, &S);
        res = LLONG_MAX;
        FOR(i, S+1) dp[i] = dp2[i] = 0;
        dp[0] = 1;
        FOR(k, m){
            scanf("%d %d", &conven[k], &ecoin[k]);
            for(int j = ecoin[k]; j <=S ; ++j){
                if(dp[j-ecoin[k]] == 0) continue;
                dp[j] = dp[j-ecoin[k]] + conven[k];
                dp2[j] = dp2[j-ecoin[k]]+1;
                if( (dp[j]-1) * (dp[j]-1) + j*j == S*S) res = min(res, dp2[j]);
                // cout << j << ' ' << dp[j] << endl;
            }
        }
        // cout << res << endl;
        if(res!= LLONG_MAX ) cout << res << endl;
        else cout << "not possible\n";
    }
}