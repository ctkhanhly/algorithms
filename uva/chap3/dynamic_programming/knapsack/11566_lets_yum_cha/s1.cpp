#include <iostream>
using namespace std;


//AC
const int N = 10;
const int K = 100;
const int T = 20;
const int X = 100;
const int INF = -1;

#define EPS 1e-6
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,x,t,k, p,tea,bill;
double dp[2*(N+1)+5][1200], res,f, favNum;
int main(){
    while(scanf("%d %d %d %d", &n, &x, &t, &k), n || x || t || k){
        bill = x*(n+1)/1.1 + EPS;
        tea = t*(n+1);
        bill -= tea;
        
        FOR(i, 2*(n+1)+1) FOR(j, bill+1) dp[i][j] = 0; 
        dp[0][0] = res = 1;
        FOR(i,k){
            scanf("%d", &p);
            favNum = 0;
            FOR(j, n+1) scanf("%lf", &f), favNum +=f;
            favNum /= (n+1);
            
            for(int e = 2*(n+1); e >= 1; --e){
                for(int j = bill; j >= p; --j){
                    if(dp[e-1][j-p]) dp[e][j] = max(dp[e][j], dp[e-1][j-p] + favNum);
                    if(j >= 2*p && e >= 2 && dp[e-2][j-2*p]) dp[e][j] = max(dp[e][j], favNum*2 + dp[e-2][j-2*p]);
                    res = max(res, dp[e][j]);
                }
            }
           
        }
        res -= 1;
        printf("%.2lf\n", res);
    }   
}