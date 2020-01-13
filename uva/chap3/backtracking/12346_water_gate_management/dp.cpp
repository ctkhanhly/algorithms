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
ll res, V,v,c;
lli wg[N];

int main(){
    scanf("%d", &n);
    FOR(z, n) scanf("%lld %d", &wg[z].fi, &wg[z].se);
    scanf("%d", &m);
    FOR(z,m) {
        scanf("%lld %d", &V, &T);
        res = INF;
        FOR(i,(1 <<n)){
            v=c=0;
            FOR(j,n){
                if(i &(1<<j)) c += wg[j].se, v += wg[j].fi;
                if(v*T >= V){ res = min(res, c); break; }
            }
        }
        printf("Case %d: ", z+1);
        if(res == INF) printf("IMPOSSIBLE\n");
        else printf("%lld\n", res);
    }
}