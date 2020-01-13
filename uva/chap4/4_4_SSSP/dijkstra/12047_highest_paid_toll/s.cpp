#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define pb push_back
#define fi first
#define se second
#define FOR(i,n) for(int i =0; i < (int)n; ++i)
#define DEBUG

const int N = 1e4, M = 1e5, P = 1e6;
const ll INF = 1e11+5;

int s,t,p, u,v,c,r,T,n,m, d, start;

ll distS[N];
ll distT[N];
vector<pair<int,ii>> edges;
vector<ii> adj[N];
vector<ii> adjT[N];
vector<ii>* g;
void dijkstra(){
    set<ii> st;
    st.insert({0,s});
    distS[s]= 0;
    while(!st.empty()){
        u = st.begin()->se, d = st.begin()->fi;
        st.erase(st.begin());
        if(d > distS[u]) continue;
        FOR(i, adj[u].size()){
            v = adj[u][i].se, c = adj[u][i].fi;
            if(distS[u] + c < distS[v]){
                st.erase({distS[v], v});
                distS[v] = distS[u] + c;
                st.insert({distS[v], v});
            }
        }
    }
}
void dijkstraReverse(){
    set<ii> st;
    st.insert({0,t});
    distT[t] = 0;
    while(!st.empty()){
        u = st.begin()->se, d = st.begin()->fi;
        st.erase(st.begin());
        // cout << u << ' ' << d << endl;
        if(d > distT[u]) continue;
        FOR(i, adjT[u].size()){
            v = adjT[u][i].se, c = adjT[u][i].fi;
            if(distT[u] + c < distT[v]){
                st.erase({distT[v], v});
                distT[v] = distT[u] + c;
                st.insert({distT[v], v});
            }
        }
    }
}
int main(){
    cin >> T;
    FOR(z, T){
        edges.clear();
        cin >> n >> m >> s >> t >> p;
        FOR(i,n) { adj[i].clear(); adjT[i].clear();  distS[i] = distT[i] = INF; } //FOR(j,n) distS[i][j] = distT[i][j] = INF;}
        FOR(q, m){
            cin >> u >> v >> c;
            edges.pb({c, {--u,--v}});
            adj[u].pb({c,v});
            adjT[v].pb({c,u});
        }
        --s,--t;
        start = s, g = adj,dijkstra();
        start = t, g = adjT, dijkstraReverse();
        r = -1;
        FOR(i,m){
            u = edges[i].se.fi, v = edges[i].se.se, c = edges[i].fi;
            if(distS[u] + c + distT[v] <= P && distS[u] + c + distT[v] <= p) {
                // cout << u << ' ' << v  << ' ' << distS[u] << ' ' << c << ' ' << distT[v] << ' ' << distS[u] + c + distT[v]<< endl;
                r = max(r, c);
            }
        }

        #ifndef DEBUG
        // FOR(i,n) { FOR(j,n) cout<< distS[i][j] << ' '; cout << endl;}
        // FOR(i,n) { FOR(j,n) cout<< distT[i][j] << ' '; cout << endl;}
        FOR(i,n) cout << distS[i] << ' ';
        cout << endl;
        FOR(i,n) cout << distT[i] << ' ';
        cout << endl;
        #endif

        cout << r << endl;
    }
}