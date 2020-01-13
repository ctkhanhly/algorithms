#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
const int N = 500;
const int B = 500;
const int INF = 5;
int n,b, T,mf,matched[N],w;
vi g[B];
vector<bool> visited(B);
bool augment(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    FOR(i, g[u].size()){
        int v = g[u][i];
        if(matched[v] == -1 || augment(matched[v])){
            matched[v] = u;
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d %d", &b, &n);
        FOR(i,n) matched[i] = -1;
        FOR(i,b) {
            g[i].clear();
            FOR(j,n) {
                scanf("%d", &w); 
                if(w) g[i].pb(j);
            }
        } 
        FOR(j,n) matched[j] = -1;
        mf = 0;
        FOR(i,b){
            visited.assign(b,0);
            mf += augment(i);
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", z+1, mf);
    }
}
//https://yuting-zhang.github.io/uva/2016/12/24/UVa-11138.html
//AC