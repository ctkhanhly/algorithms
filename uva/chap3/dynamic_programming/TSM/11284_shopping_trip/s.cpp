#include <iostream>
#include <queue>
using namespace std;


typedef pair<double,int> ii;
#define FOR(i,n) for(int i =0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 50;
const int M = 1000;
const int P = 12;
int n,m, p,T, s,e, stores[P],visited,u;
double d, dist[N+1][N+1],save[P], dp[P][N][1<<P], INF, stay,ans,cost;

double tsp(int i, int store, int bm){
    if(bm == (1<<p)-1) return 0;
    if(dp[i][store][bm] != -1) return dp[i][store][bm];
    double res = INF;
    FOR(j, p){
        if(!(bm & (1<<j)) ){
            if(dist[store][ stores[j] ] != -1) 
                res = min(res, dist[store][ stores[j] ]+ tsp(j, stores[j], bm | (1<<j)));
            res = min(res, save[j] + tsp(i,store, bm | (1<<j)));
        }
    }
    return dp[i][store][bm] = res;
}
void dijkstra(int sr, int dest){
    priority_queue<ii> pq;
    pq.push({0,sr});
    visited = 1<<sr; cost = 0;
    ii pa;
    while(!pq.empty()){
        pa = pq.top(), u  = pa.se, cost += pa.fi;
        pq.pop();
        if(u == dest) return;
        FOR(v, n+1){
            if(dist[u][v] != -1 &&  !(visited & (1<<v))){
                pq.push({dist[u][v], v});
                visited |= (1 <<v);
            }
        }
    }
   cost = -1;
}
int main(){
    scanf("%d", &T);
    FOR(t,T){
        scanf("%d %d", &n, &m);
        INF = 0;
        FOR(i, n+1) FOR(j, n+1) dist[i][j] = -1;
        FOR(i,m) scanf("%d %d %lf", &s,&e,&d), dist[s][e] = dist[e][s] = d, INF = max(INF, d);
        scanf("%d", &p);
        stay = 0;
        FOR(i,p) scanf("%d %lf", &stores[i], &save[i]), stay += save[i];
        INF= INF*m +500;
        ans = INF;
        cout << stay << endl;
        FOR(i,p){
            // if(dist[0][stores[i]] == -1) continue;
            dijkstra(0, stores[i]);
            if(cost == -1) continue;
            FOR(j,p) FOR(q,n+1) FOR(k, 1<<p) dp[j][q][k] = -1;
            ans = min(ans, cost + tsp(i, stores[i], 1<<i));
            cout << ans << endl;
        }
        cout << ans << endl;
        if(ans > stay) printf("Don’t leave the house\n");
        else printf("Daniel can save %.2lf\n",stay-ans);
    }
}
//deal with double
//https://github.com/morris821028/UVa/blob/master/volume112/11284%20-%20Shopping%20Trip.cpp