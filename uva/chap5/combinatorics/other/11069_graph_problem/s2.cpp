#include <stdio.h>
using namespace std;

int n, dp[80];

int main(){
    dp[0] = dp[1] = 1, dp[2] = 2;
    //010, 01=> cannot start a sequence w 1 b/c last end maybe 1
    //0s never exeeds 00
    for(int i = 3; i <= 76; ++i){
        dp[i] = dp[i-2] + dp[i-3];
    }
    while(scanf("%d", &n) == 1){
        printf("%d\n", dp[n]);
    }
}