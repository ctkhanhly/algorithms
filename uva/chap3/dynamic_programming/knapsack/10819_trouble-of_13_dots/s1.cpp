#include <iostream>
using namespace std;


//AC
const int N = 100;
const int M = 10000;
const int F = 5;
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
int m,n,dp[M+300], res,p,f;

int main(){
    while(scanf("%d %d", &m, &n) == 2){
        FOR(j,m+201) dp[j] = 0;
        dp[0] = 1;
        res = 1;
        // if(m > 1800) m += 200;
        FOR(i, n) {
            scanf("%d %d", &p, &f);
            for(int j = m+200; j >= p; --j){
                //dp[j] = dp[i-1][j]
                if(dp[j-p] == 0) continue;
                dp[j] = max(dp[j-p] + f, dp[j]);
                if( j <= m || (j > 2000 && j <= m +200)) res = max(res, dp[j]);
            }

        }
        cout << res-1 << endl;
    }
}