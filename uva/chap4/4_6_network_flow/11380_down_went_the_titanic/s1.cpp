#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;



//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 30;
const int V = 2000;
const int INF = 2000;
const int E = 12000;
int X,Y, P, idx,s,t, elast[V],q[V], dist[V], eid,r,c,front, back, saver,z, d;
int ecap[E], epar[E], tail[E], encode[N][N];
char g[N][N];
string str;
int dir[] = {0,-1,0,1,0};

//res graph
void addEdge(int u, int v, int w1, int w2){
    ecap[eid] = w1, tail[eid] = v, epar[eid] = elast[u], elast[u] = eid++;
    ecap[eid] = w2, tail[eid] = u, epar[eid] = elast[v], elast[v] = eid++;
}

bool bfs(){
    front = back = 0;
    q[back++] = s;
    int u,v;
    FOR(i, idx) dist[i] = INF;
    dist[s] = 0;
    while(front < back){
        u = q[front++];
        for(int i = elast[u]; i != -1; i = epar[i]){
            v = tail[i];
            if(ecap[i] > 0 && dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                q[back++] = v;
            }
        }
    }
    return dist[t] != INF;
}

int dfs(int u, int f){
    if(f == 0 || u == t) return f;
    int bflow = 0;
    for(int i = elast[u]; i!= -1; i = epar[i]){
        int v = tail[i];
        if(ecap[i] > 0 && dist[v] == dist[u]+1){//next layer
            int p = dfs(v, min(f, ecap[i]));
            ecap[i] -= p;
            ecap[i^1] += p;
            bflow += p;
            f -= p;
            if(f == 0) break;
        }
    }
    return bflow;
}

int main(){
    z = 0;
    while(scanf("%d %d %d", &X, &Y, &P) == 3){
        idx = s = eid = 0;
        t = ++idx, ++idx;
        FOR(i, V) elast[i] = -1;

        getline(cin, str);
        //graph modeling
        FOR(i, X){
            getline(cin, str);
            FOR(j, Y){
                g[i][j] = str[j];
                if(g[i][j] != '~'){
                    encode[i][j] = idx++;

                    //vertex splitting
                    if(g[i][j] == '*' || g[i][j] == '.') addEdge(idx-1, idx, 1,0);
                    else addEdge(idx-1, idx, INF,0);
                    
                    if(g[i][j] == '*') addEdge(s, idx-1, 1,0);
                    if(g[i][j] == '#') addEdge(idx, t, P,0);

                    ++idx;
                }
            }
        }

        //add neighbors
        FOR(i,X) FOR(j,Y){
            if(g[i][j] != '~'){
                FOR(k,4){
                    r = i + dir[k], c = j + dir[k+1];
                    if(0 <= r && r < X && 0 <= c && c < Y && g[r][c] != '~') {
                       //out to in 
                        addEdge(encode[i][j]+1, encode[r][c], INF,0);
                    }
                }
                
            }
        }
        
        //solve
        saver = d = 0;
        while(bfs()){
            saver += dfs(s, INF);
        }
        cout << saver << endl;
        ++z;
    }
}

//credits to Neal Wu's implementation from
//http://www.cs.cmu.edu/afs/cs/academic/class/15451-f14/www/lectures/lec11/dinic.pdf