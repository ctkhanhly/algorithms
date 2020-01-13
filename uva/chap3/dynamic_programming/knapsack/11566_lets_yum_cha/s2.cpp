#include <iostream>
#include <math.h>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define EPS 1e-6
//10,100,20,100
const int N = 10;
const int X = 100;
const int T = 20;
const int K = 100;
const int INF = -300;//10*22
int n,x,k,t, budget, price[K],f;
double fav[K],dp[K+1][1200][25],res;

double solve(int i, int cost, int dishes){
    if(cost > budget || dishes > 2*(n+1)) return INF;//so that x*summation fav[i] < 0a
    if(dp[i][cost][dishes] != -1) return dp[i][cost][dishes];
    if(dishes == 2*(n+1) || i == k ) return 0;
    return dp[i][cost][dishes] = max(solve(i+1, cost, dishes), 
    max(2*fav[i] + solve(i+1, cost + 2*price[i], dishes+2), fav[i] + solve(i+1, cost + price[i], dishes+1)));
}
int main(){
    while(scanf("%d %d %d %d", &n, &x, &t, &k), n || x || t || k){
        budget = floor(double(x*(n+1))/1.1 + EPS);
        FOR(i, k){
            scanf("%d", &price[i]);
            fav[i] = 0;
            FOR(j, n+1) scanf("%d", &f), fav[i] += f;
            fav[i] /= (n+1);
        }
        FOR(i,k+1) FOR(j, budget+1) FOR(l, 2*(n+1)+1) dp[i][j][l] = -1;
        res = solve(0, t*(n+1), 0);
        printf("%.2lf\n", res);
    }
}