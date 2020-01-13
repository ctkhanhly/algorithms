#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;


//AC
typedef vector<int> vi;
typedef long long ll;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
const int S = 0;
const int T = 1;
const int N = 50;
const int INF_D = 51;
const ll INF = 2*1e11;
int n,m,u,v,w;
ll res[N][N], g[N][N],mf,f;
vi p(N);
unordered_set<int> A;
void augment(int v, ll minEdge){
    if(v == S) f = minEdge;
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] +=f;
    }
}
int main(){
    while(scanf("%d %d", &n, &m), n || m){
        FOR(i,n) FOR(j,n) res[i][j] = g[i][j] = 0;
        FOR(i, m) scanf("%d %d %d", &u, &v, &w), --u,--v, res[u][v] = res[v][u] += w, g[u][v] = g[v][u] = w;
        A.clear();
        // mf = 0;
        while(1){
            vi dist(N, INF_D);
            p.assign(n, -1);
            f = dist[S] = 0; 
            queue<int> q;
            q.push(S);
            while(!q.empty()){
                u = q.front();
                q.pop();
                if(u == T) break;
                FOR(v,n){
                    if(res[u][v] > 0 && dist[v] == INF_D){
                        dist[v] = dist[u] +1, p[v] = u, q.push(v);
                    }
                }
            }
            augment(T, INF);
            if(f == 0){
                FOR(i,n) if(dist[i] != INF_D) A.insert(i);
                for(auto i = A.begin(); i != A.end(); ++i){
                    u = *i;
                    FOR(v, n) if(g[u][v] && !A.count(v)) printf("%d %d\n", u+1, v+1);
                }
                puts("");
                break;
            }
            // mf += f;
        }
    }
}