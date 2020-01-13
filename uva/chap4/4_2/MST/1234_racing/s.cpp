#include <iostream>
#include <algorithm>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define pb push_back


const int M = 100001;
const int N = 10001;
const int W = 1001;
int p1,p2,m,n, u,v,w,c, cost, tot,V;
// pair<int, ii> edges[M];
// pair<int, ii> tempE[M];
vector<pair<int, ii>> edges;
int p[N], rk[N], nu;
// void cnt_sort(){
//     int wt[W] = {},i;
//     FOR(i, W-1) ++wt[edges[i].fi];
//     for(i = W-2; i >= 0; --i) wt[i]+= wt[i+1];
//     FOR(i,m) edges[--wt[tempE[i].fi]] = tempE[i];
// }
class UnionFind{
public:
    UnionFind(){
    }
    void reset(int _n){
        nu = _n;
        FOR(i, nu) p[i] = i;
        FOR(i, nu) rk[i] = 1;
    }
    int find(int c){
        return p[c] = p[c] == c ? c : find(p[c]);
    }
    bool merge(int a, int b){
        p1 = find(a), p2 = find(b);
        if(p1 == p2) return false;
        if(rk[p1] < rk[p2]) swap(p1,p2);
        p[p2] = p1;
        rk[p1] += rk[p2];
        return true;
    }
};
UnionFind uf;
int main(){
    while(cin >> c, c){
        cin >> n >> m;
        edges.clear();
        tot = cost = V = 0;
        uf.reset(n);
        FOR(z, m){
            cin >> u >> v >> w;
            // cin >> tempE[z].se.fi >> tempE[z].se.se >> tempE[z].fi;
            // tempE[z] = {-w,{u,v}};
            edges.pb({-w,{u,v}});
            tot += w;
            // cout << w << endl;
        }
        // cnt_sort();
        sort(edges.begin(), edges.end());
        FOR(i, m){
            u = edges[i-1].se.fi, v = edges[i-1].se.se, w = -edges[i-1].fi;
            // cout << u << ' ' << v << ' ' << w << endl;
            if(uf.merge(u,v)){
                // cout << w << endl;
                cost += w;
                ++V;
            }
            if(V == n-1) break;
        }
        // cout << tot << ' ' << cost << endl;
        cout << tot-cost << endl;
    }
    
}
/*

case 1 : in a cycle => in a possible circuit=> leaves out min edge
case 2: not in a cycle=> these edges are needed to connect to these junctions in MST
if there are multiple edges connect to these junctions, these junctions should have 
been in a cycle since there is a path from this
junction to any other junction in the graph
*/