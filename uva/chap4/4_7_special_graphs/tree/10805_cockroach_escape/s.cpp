#include <iostream>
#include <vector>
using namespace std;


typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
#define pb push_back
const int N = 25;
const int INF = 30;
int n, m,z,T, res,x,visited,q[N], dist[N], front, back,u,v;
vi edges[N];
void dfs(int i){
    int nei = 0;
    visited |= (1<<i);
    FOR(j, edges[i].size()){
        int w = edges[i][j];
        if(!(visited &(1<<w))) ++nei, dfs(w);
    }
    if(nei==0) x = i;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d %d", &n, &m);
        FOR(i, n) edges[i].clear(),dist[i] = INF;
        FOR(i,m) scanf("%d %d", &u, &v), edges[u].pb(v), edges[v].pb(u);
        visited = 0;
        dfs(0); 
        front = back = visited = 0;
        q[back++] = x;
        res = 0;
        dist[x] = 0;
        while(front < back){
            u = q[front++];
            FOR(i, edges[u].size()){
                v = edges[u][i];
                if(dist[v] == INF) q[back++] = v, dist[v] = dist[u]+1, res = max(res, dist[v]);
            }
        }
        FOR(i,n) cout << dist[i] << ' ';
        cout << endl;
        if(z) puts("");
        printf("Case %d:\n%d\n", z+1, res);
    }
}