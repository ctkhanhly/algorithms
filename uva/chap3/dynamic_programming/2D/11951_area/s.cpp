#include <iostream>
#include <map>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
const int N = 100;
int T, m,n,K, S,sc;
map<int,ll> areas;
ll g[N][N],P,totPrice, price;
//goal: maximize area, not price
int main(){
    scanf("%d", &T);
    FOR(t, T){
        
        scanf("%d %d %d", &n, &m, &K);
        FOR(r, n) FOR(c, m) {
            scanf("%lld", &g[r][c]);
            if(r) g[r][c] += g[r-1][c];
            // cout << g[r][c] << ' ';
        }
        // areas.clear();
        // FOR(sr, n) for(int er = sr; er <n; ++er){
        //     totPrice = 0;
        //     sc = 0;
        //     FOR(ec, m){
        //         price = g[er][ec];
        //         if(sr) price -= g[sr-1][ec];
        //         // totPrice = totPrice + price > K ? price : totPrice + price;
        //         if(totPrice + price > K) sc = ec, totPrice = price;
        //         else totPrice += price;
        //         if(totPrice <= K){
        //             S = (er-sr+1)*(ec-sc+1);
        //             cout << S << ' ' << totPrice << ' ' << K<< endl;
        //             if(!areas.count(S) || (areas.count(S) && totPrice < areas[S])) areas[S] = totPrice;
        //         }
        //     }
        // }
        // S = areas.rbegin()->first, P = areas.rbegin()->second;
        //kardane on the column
        printf("Case #%d: %d %lld\n", t+1, S, P);
    }
}