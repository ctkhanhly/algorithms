#include <iostream>
#include <algorithm>
using namespace std;

//AC
typedef long long ll;
typedef pair<ll,int> lli;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second

const ll INF = 20*1e9+100;
const int N = 20;
int n, m, T;
ll res, V;
lli wg[N];
void flushCost(ll c, ll v, int i){
    if(c > res) return;
    if(v >= V) {res = min(res, c);}
    else if(i==n) { if(v >= V) res = min(res,c);}
    else{
        for(int j = i; j < n; ++j){
            flushCost(c,v,j+1);
            flushCost(c+ wg[j].se, v+ wg[j].fi*T, j+1);
        }
    }
}
int main(){
    scanf("%d", &n);
    FOR(z, n) scanf("%lld %d", &wg[z].fi, &wg[z].se);
    scanf("%d", &m);
    FOR(z,m) {
        scanf("%lld %d", &V, &T);
        res = INF;
        flushCost(0,0,0);
        printf("Case %d: ", z+1);
        if(res == INF) printf("IMPOSSIBLE\n");
        else printf("%lld\n", res);
    }
}