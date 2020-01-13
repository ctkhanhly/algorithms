#include <iostream>
#include <algorithm>
using namespace std;


//AC
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, int> lli;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second
const int N = 20;
const ll MXCOST = 20*1e9 + 100;
int n,m,T;
ll res,V;
bool comp(const lli& p1, const lli& p2){
    return p1.se == p2.se ? p1.fi > p2.fi : p1.fi < p2.fi;
}
lli wg[N];

//O((20)^2*1000) + O(19^2*999) etc = 4*1e2*1e3 =~1e5
ll flushCost(int i, int t, ll v, ll c){//time constraint is irrelevant=> all of them can flush in parallel
    if(v >= V) return c;
    if(i == n) return v >= V ? c : MXCOST; //return v >= V && t <= T ? c : MXCOST;
    ll mn = MXCOST;
    for(int j = i; j < n; ++j){
        for(int ti = 0; ti <= T; ++ti){
            if(ti == 0) mn = min(mn, flushCost(j+1, t, v, c));
            else mn = min(mn, flushCost(j+1, t+ ti, v + wg[j].fi * ti, c + wg[j].se));
        }
    }
    return mn;
}
int main(){
    scanf("%d", &n);
    FOR(z,n) scanf("%lld %d", &wg[z].fi, &wg[z].se);
    sort(wg, wg+n, comp);//dont need to sort b/c im bruteforcing anyway!
    scanf("%d", &m);
    FOR(z, m) {
        scanf("%lld %d", &V, &T);
        res = flushCost(0, 0, 0,0);
        printf("Case %d: ", z+1);
        if(res == MXCOST) printf("IMPOSSIBLE\n");
        else printf("%lld\n", res);
    }

}