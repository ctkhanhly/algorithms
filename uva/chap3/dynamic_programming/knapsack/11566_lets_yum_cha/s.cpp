#include <iostream>
using namespace std;

const int N = 10;
const int K = 100;
const int T = 20;
const int X = 100;
const int INF = -1;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,x,t,k, p,before,cost;
double dp[150000][2*N+1], res,f, favNum, bill;
int backtrack(int i, int cost, int dishes, int favor){
    if(cost > x*(n+1)) return -1;
    if(dishes == 2*n+1){
        if((int)((cost*1.1+T*(n+1))*1.1 +0.5) <= x*(n+1)) return favor;
        else return -1;
    }
    if(i==n) {
        if((int)((cost*1.1+T*(n+1))*1.1 +0.5) <= x*(n+1) ) return (double)favor/(n+1);
        else return -1;
    }
    
    else{
        int ans = favor;
        ans = max(ans, backtrack(i+1, cost+ price[i], dishes+1, favor + fav[i]));
        ans = max(ans, backtrack(i+1, cost, dishes, favor));
    }
}
int main(){
    while(scanf("%d %d %d %d", &n, &x, &t, &k), n || x || t || k){
        bill = x*(n+1);
        dp[0] = res = 1;
        FOR(i,k){
            scanf("%d", &p);
            favNum = 0;
            FOR(j, n+1) scanf("%lf", &f), favNum +=f;
            favNum /= (n+1);
            cost = (int)((p + T*(n+1)) * 1.1 + 0.5);
            for(int j = bill; j >= cost; --j){
                before = (int)(((int)(j/1.1) -p)*1.1 +0.5);
                if(before < 0 || dp[before] == 0) continue;
                dp[j] = max(dp[j], dp[before] + favNum);
                res = max(res, dp[j]);
            }
        }
        res -= 1;
        printf("%.2lf\n", res);
    }   
}