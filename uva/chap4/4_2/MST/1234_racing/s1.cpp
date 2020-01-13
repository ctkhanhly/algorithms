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
vector<pair<int, ii>> edges;
int p[N], rk[N], nu;

//AC
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
    cin >> c;
    FOR(z,c){
        cin >> n >> m;
        edges.clear();
        tot = cost = V = 0;
        uf.reset(n);
        FOR(z, m){
            cin >> u >> v >> w;
            edges.pb({-w,{u,v}});
            tot += w;
        }
        sort(edges.begin(), edges.end());
        for(int i = 0; i < m; ++i){
            u = edges[i].se.fi, v = edges[i].se.se, w = -edges[i].fi;
            if(uf.merge(u,v)){
                tot-=w;
                ++V;
            }
            if(V == n-1) break;
        }
        cout << tot << endl;
    }
    cin>> c;
    
}