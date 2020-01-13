#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define f first
#define s second
typedef vector<int> vi;
typedef pair<int,int> ii;

const int V = 2000;
int T,M,N, w, cost,i,u,v, numE;
string B,C,dum;
unordered_map<string,int> pts;
vector<pair<int, ii>> edges;

class UnionFind{
    int rk[V], p[V],n,p1,p2;
public:
    UnionFind(int _n): n(_n){
        FOR(i, n) rk[i] = 1;
        FOR(i, n) p[i] = i;
    }
    void reset(int _n){
        n = _n;
        FOR(i, n) rk[i] = 1;
        FOR(i, n) p[i] = i;
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
} uf(V);
int main(){
    cin >> T;
    getline(cin, dum);
    FOR(z, T){
        if(z) cout << endl;
        cin >> M >> N;
        i = 0;
        pts.clear();
        uf.reset(M);
        edges.clear();
        cost = 0;
        FOR(l, N){
            cin >> B >> C >> w;
            if(pts.count(B)) u = pts[B];
            else pts[B] = u = ++i;
            if(pts.count(C)) v = pts[C];
            else pts[C] = v = ++i;
            edges.pb({w, {u,v}});
        }
        sort(edges.begin(), edges.end());
        FOR(j, edges.size()){
            w = edges[j].f, u = edges[j].s.f, v = edges[j].s.s;
            if(uf.merge(u,v)){
                cost+= w;
                ++numE;
            }
            if(numE == M-1) break;
        }
        cout << cost << endl;
    }
}