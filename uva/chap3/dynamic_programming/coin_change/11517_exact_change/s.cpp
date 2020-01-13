#include <iostream>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int MONEY = 20000;
const int N = 100;
const int INF = N+1;
int dp[MONEY+5], price,n,T, coin,pay, cnt;
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d", &price);
        scanf("%d", &n);
        // cout << price << ' ' << n << endl;
        pay = MONEY, cnt = INF;
        FOR(i, MONEY+1) dp[i] = INF;
        dp[0] = 1;
        // cout << "here\n";
        FOR(i,n) {
            // cout << i << endl;
            scanf("%d", &coin);
            for(int j = MONEY; j >= coin; --j){
                if(dp[j-coin] == INF) continue;
                dp[j] = min(dp[j], dp[j-coin] +1);
                if(j < pay && j >= price) cnt = dp[j]-1, pay = j;
                else if(j == pay) cnt = min(cnt, dp[j]-1);
            }
            // cout << coin << endl;
        }
        cout << pay << ' ' << cnt << endl;
    }
}