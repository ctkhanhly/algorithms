#include <iostream>
using namespace std;

//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 605;
const int K = 305;
int n, k, dp[N][K],d;
ll dist[N+5];
int minWalk(int at, int day){
    if(day == 0) return dist[n+1]-dist[at];
    if(dp[at][day] != -1) return dp[at][day];
    int ans = dist[n+1];
    for(int i = at+1; i <= n-day+1; ++i){
        ans = min(ans, max((int)(dist[i]-dist[at]), minWalk(i, day-1)));
    }
    return dp[at][day] = ans;
}
int main(){
    while(scanf("%d %d", &n, &k) == 2){
        dist[0] = 0;
        FOR(i,n+1) FOR(j,k+1) dp[i][j] = -1;
        FOR(i, n+1) scanf("%d", &d), dist[i+1] = dist[i] + d;
        cout << minWalk(0, k) << endl;
    }
}