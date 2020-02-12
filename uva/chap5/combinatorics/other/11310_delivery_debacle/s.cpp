#include <stdio.h>
using namespace std;


//AC
typedef long  long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int t,n;
ll dp[45];
int main(){
    scanf("%d", &t);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    //unique ways to add only 3 cases: 2*1, 2*2, 2*3 that don't overlap with subcase
    for(int i= 3; i <= 40;  ++i) dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
    FOR(z,t){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
}