#include <iostream>
using namespace std;
//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 30001;
int coins[] = {1,5,10,25,50},n,m;
ll dp[N+5];
int main(){
    while(scanf("%d", &n) ==1){
        FOR(i, n+1) dp[i] = 0;
        dp[0] = 1;
        FOR(i,5) for(int j = coins[i]; j <= n; ++j) dp[j] += dp[j-coins[i]];
        if(dp[n] == 1) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
    }
}