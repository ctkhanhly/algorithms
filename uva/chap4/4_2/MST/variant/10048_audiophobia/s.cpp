#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int C = 101;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)

int c1,c2,d, c,S,Q,u,v,w,z, ans;
vector<ii> MST[C];
vector<pair<int,ii>> edges;
int p[C], rk[C],p1,p2;
bool visited[C];
const int MAXD = 100000; //7080
class UnionFind{
public:
    void reset(){
        FOR(i,c+1) p[i] = i, rk[i] = 1;
    }
    int find(int i){ return p[i] = i == p[i] ? i : find(p[i]);}
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
void krustal(){
    FOR(i,S){
        u = edges[i].se.fi, v = edges[i].se.se, d = edges[i].fi;
        if(uf.merge(u,v)){
            MST[u].pb({d,v});
            MST[v].pb({d,u});
            // if(uf.find(c1) == uf.find(c2)) {ans = d; return;}
        }
        
    }
}
void bfs(){
    queue<ii> q;
    q.push({0,c1});
    FOR(i,c+1) visited[i] = false;
    ans = -1;
    visited[c1] = true;
    while(!q.empty()){
        u = q.front().se, d = q.front().fi, q.pop();
        if(u == c2) {ans = d; break;} 
        FOR(i,MST[u].size()){
            v = MST[u][i].se, w = MST[u][i].fi;
            if(!visited[v]){
                q.push({max(d,w),v});
                visited[v]= true;
            }
        } 
    }
}
int main(){
    z = 1;
    while(cin >> c >> S >> Q, c || S || Q){
        if(z>1) cout << endl;
        edges.clear();
        // uf.reset();
        FOR(i, c+1) MST[i].clear();
        FOR(i, S){
            cin >> c1 >> c2 >> d;
            edges.pb({d, {c1,c2}});
        }
        uf.reset();
        sort(edges.begin(), edges.end());
        krustal();
        cout << "Case #" << z << endl;
        // FOR(i, S) cout << edges[i].fi << ' ';
        // cout << endl;
        FOR(q, Q){
            cin >> c1 >> c2;
            ans = -1;
            // uf.reset();
            // krustal();
            ans = -1;
            bfs();
            if(ans != -1) cout << ans << endl;
            else cout << "no path" << endl;
            // FOR(i, c) MST[i].clear();
        }
        ++z;
    }
}