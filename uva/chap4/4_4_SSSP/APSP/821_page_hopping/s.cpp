#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
#define pb push_back
#define fi first
#define se second
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define DEBUG

//AC
const int N = 100;
const int INF = 101;
int a,b, z,m, n,V;
double dist;
int g[N][N];
unordered_set<int> vertices;
void Warshal(){
    FOR(k,n)
        FOR(u,n)
            FOR(v,n)
                g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
}
int main(){
    z = 1;
    while(cin >> a >> b, a && b){
        m = 1;
        FOR(i,N) FOR(j,N) g[i][j] = INF;
        n = max(n, max(a,b));
        g[--a][--b] = 1;
        V = 2;
        vertices.clear();
        vertices.insert(a), vertices.insert(b);
        while(cin >> a >> b, a && b) {
            n = max(n, max(a,b));
            g[--a][--b] = 1;
            if(!vertices.count(a))++V;
            if(!vertices.count(b)) ++ V;
            vertices.insert(a), vertices.insert(b);
        }
        #ifndef DEBUG
        // FOR(i,n) {FOR(j,n) cout << g[i][j] << ' '; cout << endl;}
        #endif
        dist = 0;
        Warshal();
        #ifndef DEBUG
        FOR(i,n) {FOR(j,n) cout << g[i][j] << ' '; cout << endl;}
        //cout << u+1 <<' ' << v+1 << ' ' << g[u][v] << endl,
        #endif
        FOR(u,n)
            FOR(v,n)
                if(g[u][v] < INF &&  u != v) dist += g[u][v];
        #ifndef DEBUG
        cout << dist << endl;
        #endif
        printf("Case %d: average length between pages = %0.3f clicks\n", z, dist/(V*(V-1)));
        ++z;
    }
}