#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define f first 
#define s second
#define pb push_back
typedef pair<int,int> ii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

const int N = 1000;
vector<pair<double,ii>> edges;
vector<ii> vertices;
double g[N][N],roads, railroads,lim,x,y;
int T,n,r, states,u,v, numE;


class UnionFind{
    int rk[N], p[N], n;
public:
    UnionFind(int _n):n(_n){
        FOR(i, n) rk[i] = 1;
        FOR(i, n) p[i] = i;
    }
    int find(int c){
        return p[c] = p[c] == c ? c : find(p[c]);
    }
    void merge(int a, int b){
        int p1 = find(a);
        int p2 = find(b);
        if(p1 == p2) return;
        if(rk[p1] < rk[p2]) swap(p1,p2);
        p[p2] = p1;
        rk[p1] += rk[p2];
    }
    bool isSameSet(int a, int b){ return find(a) == find(b);}
};
int main(){
    cin >> T;
    FOR(z,T){
        // if(z) cout << endl;
        edges.clear();
        vertices.clear();
        cin >> n >> r;
        FOR(p, n){
            cin >> x >> y;
            vertices.pb({x,y});
        }
        FOR(p,n){
            for(int o = p+1; o < n; ++o){
                x = vertices[p].f - vertices[o].f, y = vertices[p].s - vertices[o].s;
                g[p][o] = sqrt( x*x+ y*y);
                g[o][p] = g[p][o];
                edges.pb({g[o][p], {o,p}});
            }
        }
        sort(edges.begin(), edges.end());
        states = 1, lim = roads = railroads = numE = 0;
        UnionFind uf(n);
        // UnionFind uf2(n);
        FOR(p, edges.size()){
            // cout << edges[p].f << endl;
            u = edges[p].s.f, v = edges[p].s.s;
            if(!uf.isSameSet(u,v)){
                uf.merge(u,v);
                // lim = max(lim, g[u][v]);
                // FOR(i,n) {
                //     if(uf2.isSameSet(i,u)) lim = max(g[u][i],lim);
                //     if(uf2.isSameSet(i,v)) lim = max(g[v][i],lim);
                // }
                // if(lim > r) {
                //     // cout << "lim " << lim << endl;
                //     ++states, lim = 0;
                //     railroads += edges[p].f;
                // }
                if(edges[p].f > r) ++states, railroads += edges[p].f; 
                else roads += edges[p].f;
                ++numE;
            }
            if(numE == n-1) break;
        }
        printf("Case #%d: %d %d %d\n", z+1, states, (int)(roads+0.5), (int)(railroads+0.5));
    }
}