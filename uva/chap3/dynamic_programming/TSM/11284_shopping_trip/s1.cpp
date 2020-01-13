#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<double,int> ii;
typedef long long ll;
#define FOR(i,n) for(int i =0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 50;
const int M = 1000;
const int P = 12;
const ll INF = LLONG_MAX;
int n,m, p,T, s,e, stores[P], visited,u;
double d, dist[N+1][N+1],save[P], dp[P][1<<P], stay,ans,cost;

//wrong dijkstra
void dijkstra(int sr, int dest){
    priority_queue<ii> pq;
    pq.push({0,sr});
    visited = 1<<sr; cost = 0;
    ii pa;
    while(!pq.empty()){
        pa = pq.top(), u  = pa.se, cost -= pa.fi;
        pq.pop();
        if(u == dest) return;
        FOR(v, n+1){
            if(dist[u][v] != -1 &&  !(visited & (1<<v))){
                pq.push({-dist[u][v], v});
                visited |= (1 <<v);
            }
        }
    }
   cost = -1;
}

double tsp(int i, int bm){
    if(bm == (1<<p)-1) {
        dijkstra(stores[i],0);
        if(cost == -1) cout << i << ' ' << stores[i] << " cost is -1 tsp\n";
        return cost == -1 ? INF : cost;
    }
    if(dp[i][bm] != -1) return dp[i][bm];
    double res = INF;
    FOR(j, p){
        if(!(bm & (1<<j)) ){
            if(dist[ stores[i] ][ stores[j] ] != -1) {
                double remain = tsp(j, bm | (1<<j));
                if(remain != INF) res = min(res, dist[ stores[i] ][ stores[j] ] - save[j] + remain);
            } 
            res = min(res, tsp(i,bm | (1<<j)));
        }
    }
    return dp[i][bm] = res;
}

int main(){
    scanf("%d", &T);
    FOR(t,T){
        scanf("%d %d", &n, &m);
        FOR(i, n+1) FOR(j, n+1) dist[i][j] = INF;
        FOR(i,m) {
            scanf("%d %d %lf", &s,&e,&d);
            dist[s][e] = dist[e][s] = min(dist[e][s], min(dist[s][e],d));
        }
        scanf("%d", &p);
        stay = 0;
        FOR(i,p) scanf("%d %lf", &stores[i], &save[i]), stay += save[i];
        ans = INF;
        // cout << stay << endl;
        FOR(i,p){
            // if(dist[0][stores[i]] == -1) continue;
            dijkstra(0, stores[i]);
            if(cost == -1) cout << i << " cost is -1 start\n";
            if(cost == -1) continue;
            FOR(j,p) FOR(k, 1<<p) dp[j][k] = -1;
            ans = min(ans, cost -save[i] + tsp(i, 1<<i));
            // cout << cost << ' ' << ans << endl;
            // cout << ans << endl;
        }
        // cout << ans << endl;
        if(ans > 0) printf("Don’t leave the house\n");
        else printf("Daniel can save %.2lf\n",-ans);
    }
}