#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

//AC
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
const int INF = INT_MAX;
const int C = 101;
int m,n, price[N],cost[N][C], pi, u,v,d,q,s,c,e,di,fuel,ans;
vector<ii> edges[N];
int main(){
    cin >> n >> m;
    FOR(i,n) edges[i].clear(), cin >> price[i];
    FOR(i,m) {
        cin >> u >> v >> d;
        edges[u].pb({d,v});
        edges[v].pb({d,u});
    }
    cin >> q;
    FOR(i,q){
        cin >> c >> s >> e;
        FOR(i, n) FOR(j,c+1) cost[i][j] = INF;
        set<pair<int,ii>> st;
        fuel = 0;
        st.insert({0,{s,fuel}});
        cost[s][0] = 0;
        ans = -1;
        while(!st.empty()){
            u = st.begin()->se.fi, fuel = st.begin()->se.se, di = st.begin()->fi;
            st.erase(st.begin());
            // cout << u << ' ' << fuel  << endl;
            if(u == e) {ans = cost[e][fuel]; break;}
            // if(di > cost[u][fuel]) continue;
            if(fuel+1 <= c && cost[u][fuel] + price[u] < cost[u][fuel+1]){
                st.erase({di, {u,fuel}});
                cost[u][fuel+1] = cost[u][fuel] + price[u];
                st.insert({cost[u][fuel+1], {u, fuel+1}});
            }
            for(auto it = edges[u].begin(); it != edges[u].end(); ++it){
                v = it->se, d = it->fi;
                if(d <= fuel && cost[u][fuel] < cost[v][fuel-d]){
                    st.erase({cost[v][fuel-d], {v,fuel-d}});
                    cost[v][fuel-d] = cost[u][fuel];
                    st.insert({cost[u][fuel], {v, fuel-d}});
                }
            }
        }
        if(ans != -1) cout << ans << endl;
        else cout << "impossible" << endl;
    }
}
/*
no dp b/c not DAG
if you start from s,0 to some path and figure out that does not work
you come back to s,0 again to find new path
*/