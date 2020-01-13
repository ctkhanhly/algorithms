#include <iostream>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;

//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
char s[20];
int n,r,c,c1;
ll dp[20],dp2[20], ans;
void addLast(){
    //last possible queen places
    for(c1 = 0; c1 < c-1; ++c1)
        dp2[c] += dp[c1];
    for(c1 = c+2; c1 < n; ++c1)
        dp2[c] += dp[c1];
}
int main(){
    while(scanf("%s", s)==1){
        n = strlen(s);
        FOR(i,n) dp[i] = dp2[i] = 0;
        if(s[0] == '?'){
            FOR(i, n) dp[i] = 1;
        }
        else c = isdigit(s[0]) ? s[0]-'1' : s[0]-'A'+9, dp[c] = 1;
        for(r = 1; r < n; ++r){
            if(s[r] == '?'){
                for(c = 0; c < n; ++c) addLast();
            }
            else{
                c = isdigit(s[r]) ? s[r]-'1' : s[r]-'A'+9;
                addLast();
            }
            copy(dp2, dp2+n, dp);
            fill(dp2, dp2+n,0);
        }
        ans = 0;
        ans = accumulate(dp,dp+n,ans);
        printf("%lld\n", ans);
    }
}