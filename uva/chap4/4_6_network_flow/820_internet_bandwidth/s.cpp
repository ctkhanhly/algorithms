#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef vector<int> vi;
const int N = 100;
const int INF = 1e7+10000;//all edges with max bw
int n, s,t, c, res[N][N], mf, f,z,u,v,w;
vi p(N);

void augment(int v, int minBw){
    if(v == s) f = minBw;
    else if(p[v] != -1){
        augment(p[v], min(minBw, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}
int main(){
    z = 1;
    while(scanf("%d", &n), n){
        FOR(i,n) FOR(j,n) res[i][j] = 0;
        scanf("%d %d %d", &s, &t, &c);
        --s,--t;
        FOR(i, c) 
            scanf("%d %d %d", &u, &v, &w), --u, --v, res[u][v] = res[v][u] += w;


        mf = 0;
        while(1){
            queue<int> q;
            q.push(s);
            vi dist(n,INF);
            p.assign(n, -1);
            f = dist[s] = 0;
            while(!q.empty()){
                u = q.front();
                q.pop();
                if(u == t) break;
                FOR(v, n){
                    if(res[u][v] > 0 && dist[v] == INF){
                        p[v] = u;
                        q.push(v);
                        dist[v] = dist[u] + 1;
                    }
                }
            }
            augment(t, INF);
            if(f== 0) break;
            mf += f;
        }
        printf("Network %d\n", z);
        printf("The bandwidth is %d.\n\n", mf);
        ++z;
    }
}