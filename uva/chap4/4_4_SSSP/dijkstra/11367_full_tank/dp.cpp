#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define fi first
#define se second
#define pb push_back


const int N = 1000;
const int M = 10000;
const int INF = 100001;
const int C = 101;
int m,n, price[N],cost[N][C], pi, u,v,d,q,s,c,e,di, fuel;
vector<ii> edges[N];

int recurse(int u, int c, int target, int cap){
    if(u == target) return cost[u][c];
    int res = INF;
    if(c > 0){
        for(int i = 0; i < edges[u].size(); ++i){
            int v = edges[u][i].se, d = edges[u][i].fi;
            if(d <= c && cost[u][c] < cost[v][c-d]){
                cost[v][c-d] = cost[u][c];
                res = min(res, recurse(v, c-d, target, cap));
            } 
        }
    }
    
    if(c+1 <= cap && cost[u][c] + price[u] < cost[u][c+1]){
        cost[u][c+1] = cost[u][c] + price[v];
        res = min(res, recurse(v, c+1, target, cap));
    }
}
int dp(){
    
    int res = INF;//2*E*100 = 2*M*100= 10^4*100 = 10^6
    for(int u = 0; u < n; ++u){
        for(int f = 0; f <= c; ++f){
            if(f+1 <= c){
                cost[u][f+1] = min(cost[u][f+1], cost[u][f] + price[u]);
            }
            for(int i = 0; i < edges[u].size(); ++i){
                v = edges[u][i].se, di = edges[u][i].fi;
                if(di <= f) cost[v][f-di] = min(cost[v][f-di], cost[u][f]);
            }
            
        }
    }
    FOR(f, c+1) res = min(res, cost[e][f]);
    return res;
}

int main(){
    cin >> n;
    FOR(i,n) cin >> price[i];
    cin >> m;
    FOR(i,m) {
        cin >> u >> v >> d;
    }
    FOR(i, n) FOR(j,c) cost[i][j] = INF;
    cin >> q;
    FOR(z,q){
        cin >> c >> s >> e;
    }
}