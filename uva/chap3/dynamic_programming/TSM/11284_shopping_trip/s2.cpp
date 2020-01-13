#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define EPS 1e-6
typedef long long  ll;
const int N = 50;
const int P =12;
const ll INF = LLONG_MAX;
int n, m, T,p, stores[P],e,s;

double dist[N+1][N+1], save[P], dp[P][1<<P],ans,d;
void warshal(){
    FOR(k, n+1)
        FOR(i, n+1)
            FOR(j, n+1)
                if(dist[i][k] != INF && dist[k][j] != INF) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // FOR(i,n+1) FOR(j, i) dist[i][j] = dist[j][i] = min(dist[i][j], dist[j][i]);
}
double tsp(int i, int bm){
    if(bm == (1<<p)-1) return dist[ stores[i] ][0];
    if(dp[i][bm] != -1) return dp[i][bm];
    double res = INF;
    FOR(j,p){
        if(!(bm&(1<<j))){//there must be distance from one store to another
            double remain = tsp(j, bm | (1<<j));
            if(remain != INF) res = min(res, dist[ stores[i] ][ stores[j] ] - save[j] + remain);
        } 
    }
    res = min(res, dist[stores[i]][0]);
    return dp[i][bm] = res;
}
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d %d", &n, &m);
        FOR(i, n+1) FOR(j, n+1) dist[i][j] = i==j ? 0 : INF;
        FOR(i,m) {
            scanf("%d %d %lf", &s,&e,&d);
            // dist[s][e] = dist[e][s] = min(dist[e][s], min(dist[s][e],d));
            dist[s][e] = min(dist[s][e], d);
            dist[e][s] = min(dist[e][s], d);
        }
        scanf("%d", &p);
        FOR(i,p) scanf("%d %lf", &stores[i], &save[i]);
        ans = INF;
        warshal();
        FOR(i,p){
            FOR(j,p) FOR(k, 1<<p) dp[j][k] = -1;
            ans = min(ans, dist[0][ stores[i]] - save[i] + tsp(i, 1<<i));
        }
        // cout << ans << endl;
        if(ans > 0 || abs(ans) <= EPS) printf("Don't leave the house\n");
        else printf("Daniel can save $%.2lf\n",-ans);
    }
}