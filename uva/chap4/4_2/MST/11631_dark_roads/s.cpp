#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back 
#define f first
#define s second

typedef pair<int,int> ii;
const int M = 200000;
int m,n,x,y,z, totCost, cost, u,v,c, numE;
vector<pair<int, ii>> edges;

class UnionFind{
    int rk[M], p[M], sz;
public:
    UnionFind(int _sz):sz(_sz){
        FOR(i,sz) rk[i] = 1;
        FOR(i, sz) p[i] = i;
    }
    int find(int c){ return p[c] = p[c] == c ? c : find(p[c]);}
    bool merge(int a, int b){ 
        int p1 = find(a);
        int p2 = find(b);
        if(p1 == p2) return false;
        if(rk[p1] < rk[p2]) swap(p1,p2);
        p[p2] = p1;
        rk[p1] += rk[p2];
        return true;
    }
    // bool isSameComp(int a,int b) { return find(a) == find(b);}
};

int main(){
    c = 0;
    while(cin >> m >> n, m && n){
        totCost = 0;
        edges.clear();
        // if(c) cout << endl;
        FOR(l, n){
            cin >> x >> y >> z;
            totCost += z;
            edges.pb({z, {x,y}});
        }
        sort(edges.begin(), edges.end());
        cost = numE = 0;
        UnionFind uf(m);
        FOR(l, edges.size()){
            u = edges[l].s.f, v = edges[l].s.s;
            if(uf.merge(u,v)){
                cost += edges[l].f;
                ++numE;
            }
            if(numE == m-1) break;
        }
        ++c;
        cout << (totCost - cost) << endl;
    }
}