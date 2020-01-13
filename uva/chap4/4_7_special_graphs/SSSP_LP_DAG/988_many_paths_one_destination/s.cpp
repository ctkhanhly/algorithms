#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//AC
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
#define pb push_back
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 1e5;
int dp[N],n,e,st[N],back,z;
bool visited[N];
vi edges[N];
ll ans;
void dfs(int u){
    visited[u] = 1;
    FOR(i, edges[u].size()) {
        int v = edges[u][i];
        if(!visited[v]) dfs(v);
    }  
    st[back++] = u;
}
int main(){
    z = 0;
    while(scanf("%d", &n) ==1){
        FOR(i,n+1) edges[i].clear(), dp[i] = visited[i] = 0;
        int v;
        FOR(i,n) {
            scanf("%d",&e);
            if(e == 0) edges[i].pb(n);
            FOR(j,e){
                scanf("%d", &v);
                edges[i].pb(v);
            }
            // cout << e << ' ' << edges[i].size() << endl;
        } 
        back = 0;
        dfs(0);
        --back;
        dp[0] = 1;
        int u;
        while(back >= 0){
            u = st[back--];
            FOR(i, edges[u].size()) dp[edges[u][i]] += dp[u];
        }
        ans = 0;
        // FOR(i,n) if(edges[i].size() == 0) ans += dp[i];
        if(z) cout << endl;
        cout << dp[n] << endl;
        z++;
    }
}