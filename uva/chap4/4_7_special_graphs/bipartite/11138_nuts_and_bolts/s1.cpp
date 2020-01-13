#include <iostream>
#include <vector>
using namespace std;


//AC
typedef vector<int> vi;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 500;
const int B = 500;
const int V = 1200;
const int INF = 5;
const int E = 520000;
int n,b, T,eid,vid,s,t,q[V],front,back,mf,f,dist[V],w, ecap[E], elast[V], epar[E], tail[E];
vector<ii> p(V);

void addEdge(int u, int v, int w1, int w2){
    ecap[eid] = w1, tail[eid] = v, epar[eid] = elast[u], elast[u] = eid++;
    ecap[eid] = w2, tail[eid] = u, epar[eid] = elast[v], elast[v] = eid++;
}
void augment(int u, int minEdge){
    if(u == s) f = minEdge;
    else if(u != -1){
        augment(p[u].fi, min(minEdge, ecap[p[u].se]));
        ecap[p[u].se] -= f;
        ecap[(p[u].se)^1] +=f;
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
        p.assign(vid, {-1,-1});
        while(front < back){
            u = q[front++];
            if(u == t) break;
            for(int i = elast[u]; i != -1; i = epar[i]){
                v = tail[i];
                if(ecap[i] > 0 && dist[v] == V){
                    dist[v] = dist[u] +1;
                    q[back++] = v;
                    p[v] = {u, i};
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
        eid = 0;
        vid = b+n+2;
        s = 0, t = 1;
        FOR(i, vid) elast[i] = -1;
        FOR(i,b) {
            addEdge(s, i+2, 1,0);
            FOR(j,n) {
                scanf("%d", &w); 
                if(w) addEdge(i+2, j+b+2, w,0);
            }
        } 
        FOR(j,n) addEdge(j+b+2, t, 1,0);
        mf = 0;
        EK();
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", z+1, mf);
    }
}