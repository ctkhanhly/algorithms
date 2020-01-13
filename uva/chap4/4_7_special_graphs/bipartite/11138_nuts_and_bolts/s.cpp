#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 500;
const int B = 500;
const int V = 1200;
const int INF = 5;
int n,b, T,vid,s,t,q[V],front,back,mf,f,dist[V],res[V][V]w;
vi p(V);

void augment(int u, int minEdge){
    if(u == s) f = minEdge;
    else if(u != -1){
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] +=f;
    }
}
void EK(){
    int u,v;
    while(1){
        front = back = 0;
        q[back++] = s;
        f = 0;
        FOR(i, vid) dist[i] = V;
        dist[s] = 0;
        p.assign(vid, -1);
        while(front < back){
            u = q[front++];
            if(u == t) break;
            FOR(v, vid){
                if(res[u][v] > 0 && dist[v] == V){
                    dist[v] = dist[u] +1;
                    q[back++] = v;
                    p[v] = u;
                }
            }
        }
        augment(t, INF);
        if(f == 0) break;
        mf += f;
    }
    
}
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d %d", &b, &n);
        vid = b+n+2;
        s = 0, t = 1;
        FOR(i,vid) FOR(j, vid) res[i][j] = 0;
        FOR(i,b) {
            res[s].pb(i+2);
            // res[s][i+2] = 1;
            // FOR(j,n) scanf("%d", res[i+2]+2+b+j), res[2+b+j][t] = 1;//b to n
            FOR(j,n) scanf("%d", &res[i+2][2+b+j]), res[2+b+j][t] = 1;//b to n
        } 
        mf = 0;
        EK();
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", z+1, mf);
    }
}