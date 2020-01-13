#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
 

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
const int M = 40;
const int INF = 301;
int n, m,S, conven[M], ecoin[M], dp[400][400][M], res;

int cal(int X, int Y, int i){
    if(X*X + Y*Y == S*S) return 0;
    if(i == m || X*X + Y*Y > S*S) return INF;
    if(dp[X][Y][i] != -1) return dp[X][Y][i];
    int ans = cal(X, Y, i+1);
    int x = X + conven[i], y = Y+ecoin[i];
    if(x*x + y*y <= S*S) {
        // ans = min(ans, 1 + cal(x, y, i+1));
        ans = min(ans, 1 + cal(x, y, i));
    } 
    // ans = min(ans, cal(X, Y, i+1));
    return dp[X][Y][i] = ans;
}
int main(){
    scanf("%d", &n);
    FOR(z, n){
        scanf("%d %d", &m, &S);
        res = INF;
        FOR(i, S+1) FOR(j, S+1) FOR(k,m) dp[i][j][k] = -1;
        FOR(k, m){
            scanf("%d %d", &conven[k], &ecoin[k]);
        }
        res = cal(0,0,0);
        // cout << res << endl;
        if(res != INF) cout << res << endl;
        else cout << "not possible\n";
    }
}