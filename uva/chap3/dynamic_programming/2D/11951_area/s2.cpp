#include <iostream>
#include <map>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
const int N = 100;
int T, n, m, K,S,g[N+5][N+5];
map<ll, int> areas;
ll col[N+5], totPrice,P;
map<ll,int>::iterator it;
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d %d %d", &n, &m, &K);
        FOR(i, n) FOR(j, m) scanf("%d", &g[i][j]);
        S = 0, P = 1e9;
        FOR(sr, n) {
            FOR(i, m) col[i] = 0;
                for(int er = sr; er < n; ++er){
                    areas.clear();
                    areas[0] = totPrice = 0;
                    FOR(ec, m){
                        col[ec] += g[er][ec];
                        totPrice += col[ec];
                        it = areas.lower_bound(max((ll)0,totPrice-K));
                        if(it != areas.end()){
                            if( (er-sr+1)*(ec+1) - it->second > S){
                                S = (er-sr+1)*(ec+1) - it->second;
                                P = totPrice-it->first;
                            } 
                            else if((er-sr+1)*(ec+1) - it->second == S){
                                P = min(P, totPrice-it->first);
                            }
                        }
                        if(!areas.count(totPrice)) areas[totPrice] = (er-sr+1)*(ec+1);
                    }
                }
        }
        if(S == 0) P = 0;
        printf("Case #%d: %d %lld\n", t+1, S, P);
    }
}