#include <iostream>
#include <math.h>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n;
double dp[505][505],ans,p;
int main(){
    while(scanf("%d %lf", &n, &p), n){
        FOR(i,n+1)FOR(j,n+1) dp[i][j] = 0;
        dp[0][0] = 1;
        ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                dp[i+1][j] += dp[i][j]*(1-p);
                //layer between streaks with a loss
                //each time doing this => must account for all streaks
                for(int k = 1; k <= n-i; ++k){
                    dp[i+k+1][max(j,k)] += dp[i][j]*(1-p)*pow(p,k);
                }
                //base case
                //streak till the end
                dp[n][max(j,n-i)] += dp[i][j]*pow(p, n-i);
            }
        }
        // FOR(i,n+1) {FOR(j,n+1) printf("%6.2lf", dp[i][j]); cout << endl;}
        for(int j = 0; j <= n; ++j) ans += j*dp[n][j];
        printf("%lf\n",ans);
    }
}

//https://gist.github.com/Tafhim/b5705901e33017205a3b