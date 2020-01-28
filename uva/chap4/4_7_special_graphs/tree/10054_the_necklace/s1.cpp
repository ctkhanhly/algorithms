#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


#define FOR(i,n) for(int i =0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 55;
typedef vector<int> vi;
typedef pair<int,int> ii;
int vid, n, T,u,v,t,toColor[N];
bool ans;
unordered_map<int,int> V;
vector<ii> edges[N];
void printEuler(int i){
    int nei = 0;
    FOR(j, edges[i].size()){
        ii& w = edges[i][j];
        if(w.se){
            cout << toColor[i] << ' ' << toColor[w.fi] << endl;
            w.se = 0;
            ++nei;
            FOR(k, edges[w.fi].size()){
                ii& x = edges[w.fi][k];
                if(x.fi == i && x.se) { 
                    x.se = 0; 
                    break;
                }
            }
            printEuler(w.fi);
        }
    }
    if(nei == 0) printf("%d %d\n", toColor[i], toColor[0]);
}
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d", &n);
        V.clear(), vid = 0;
        FOR(i,N) edges[i].clear();
        FOR(i,n){
            scanf("%d %d", &u, &v);
            if(!V.count(u)) V[u] = vid, toColor[vid++] = u;
            if(!V.count(v)) V[v] = vid, toColor[vid++] = v;
            edges[V[u]].pb({V[v],1});
            edges[V[v]].pb({V[u],1});
        }
        ans = 1;
        // FOR(i,vid) cout << edges[i].size() << ' ';
        // cout << endl;
        // for(auto it : V) printf("(%d %d)", it.first, it.second);
        // cout << endl;
        FOR(i,vid) {if(edges[i].size() %2) { ans = 0; break;}}
        printf("Case #%d\n", z+1);
        if(ans){
            printEuler(0);
        }
        else{
            printf("some beads may be lost\n");
        }
    }
}