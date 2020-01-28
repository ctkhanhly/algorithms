#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int INF = 400;
int n,m, T,g[400][400],u,v,res, first, second,center;
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d %d", &n, &m);
        FOR(i,n+m) {g[i][i] = 0; FOR(j,n+m) g[i][j] = INF;}
        center = n;
        FOR(i,m){
            scanf("%d %d", &u, &v);
            g[u][center] = g[center][u] = 1;
            g[v][center] = g[center][v] = 1;
            ++center;
        }
        res = INF;
        FOR(k, center) FOR(i,center) FOR(j,center) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        FOR(i,center){
            first = second = 0;
            FOR(j,n) {
                // if(i == j) continue;
                if(g[i][j] >= first){
                    second = first;
                    first = g[i][j];
                }
                else if(g[i][j] > second) second = g[i][j];
            }
            // cout << i << ' ' << first << ' ' << second << endl;
            res = min(res, first + second);
        } 
        printf("Case #%d:\n%d\n\n", z+1, res/2);
    }
}