#include <iostream>
using namespace std;


//TLE
const int N = 100;
const int M = 10000;
const int F = 5;
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
int m,n,price[N],fav[N], dp[N][M+300];
int search(int i, int cost, int favorVal){
    if(i == n) 
        return cost <= m+((cost > 2000) ? 200 : 0) ? favorVal : -1;
    if(dp[i][cost] != -1 && dp[i][cost] > favorVal) return dp[i][cost];
    int ans = 0;
    ans = max(ans, search(i+1, cost, favorVal));
    ans = max(ans, search(i+1, cost+price[i], favorVal + fav[i]));
    // for(int j = i; j < n; ++j){
    //     if(cost + price[j] <= m || (cost +price[j] > 2000 && cost+price[j] <= m+200)){
    //         ans = max(ans, search(j+1, cost+price[j], favorVal + f[j]);
            
    //     }
            
    // }
    return dp[i][cost] = ans;
}
int main(){
    while(scanf("%d %d", &m, &n) == 2){
        FOR(i,n) FOR(j,m+201) dp[i][j] = -1;
        
        FOR(i, n) {
            scanf("%d %d", &price[i], &fav[i]);
        }
        cout << search(0,0,0) << endl;
    }
}