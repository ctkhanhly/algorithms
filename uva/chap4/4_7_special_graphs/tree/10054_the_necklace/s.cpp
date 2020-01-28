#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


#define FOR(i,n) for(int i =0; i < (int)n; ++i)
#define pb push_back
const int N = 55;
typedef vector<int> vi;
int vid, n, T,u,v,t;
bool ans;
unordered_map<int,int> V;
vi edges[N];
vi p(N);
bool visited[N];

void dfs(int i){
    visited[i] = 1;
    int nei = 0;
    FOR(j, edges[i].size()){
        int w = edges[i][j];
        if(!visited[w]) p[w] = i, ++nei, dfs(w);
    }
    if(nei == 0) t = i;
}
void printAns(int i){
    if(p[i] == -1) return;
    else{
        printAns(p[i]);
        printf("%d %d\n", p[i], i);
    }
}
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d", &n);
        V.clear(), vid = 0;
        FOR(i,N) edges[i].clear();
        FOR(i,n){
            scanf("%d %d", &u, &v);
            if(!V.count(u)) V[u] = vid++;
            if(!V.count(v)) V[v] = vid++;
            edges[V[u]].pb(v);
            edges[V[v]].pb(u);
        }
        FOR(i, vid) visited[i] = 0;
        p.assign(vid, -1);
        dfs(0);
        ans = 1;
        FOR(i,vid) {if(!visited[i]) ans = 0; break;}
        if(z) puts("");
        printf("Case %d\n", z+1);
        if(ans){
            printAns(t);
        }
        else{
            printf("Some beads may be lost\n");
        }
    }
}