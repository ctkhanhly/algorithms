#include <iostream>
#include <limits.h>
using namespace std;
 

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
const int M = 40;
const int INF = 301;
int n, m,S, conven, ecoin,dp[500][500], res;
int main(){
    scanf("%d", &n);
    FOR(z, n){
        scanf("%d %d", &m, &S);
        res = INF;
        FOR(i, S+1) FOR(j, S+1) dp[i][j] = INF;
        dp[0][0] = 1;
        FOR(i, m){
            scanf("%d %d", &conven, &ecoin);
            for(int j = ecoin; j <=S ; ++j){
                for(int k = conven; k <= S; ++k){
                    if(dp[j-ecoin][k-conven] == INF) continue;
                    dp[j][k] = min(dp[j][k], dp[j-ecoin][k-conven] +1);
                    if(j*j + k*k == S*S) res = min(res, dp[j][k]-1);
                }
            }
        }
        if(res!= INF ) cout << res << endl;
        else cout << "not possible\n";
    }
}