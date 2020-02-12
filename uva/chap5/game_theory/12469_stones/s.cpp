#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n;
int dp[1005][2005];
bool play(int num, int last){
    if(dp[num][last] != -1) return dp[num][last];
    if(num <= last) return dp[num][last] = 1;
    for(int i = 1; i <= last; ++i){
        if(!play(num-i, 2*i)) return dp[num][last] = 1;
    }
    return dp[num][last] = 0;
}
int main(){
    while(scanf("%d", &n),n){
        FOR(i,n+1) FOR(j,2*n+1) dp[i][j] = -1;
        if(play(n, n-1)) printf("Alicia\n");
        else printf("Roberto\n");
    }
}