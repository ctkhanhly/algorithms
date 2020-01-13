#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> ii;
const int N = 1000;
int m, n, r, c,t,nr,nc,d;
const int INF = 9000005;
int g[N][N];
int dist[N][N];
int dir[5] = {0,1,0,-1,0};
int main(){
    cin >> t;
    FOR(z,t){
        cin >> n >> m;
        FOR(r,n){
            FOR(c, m) cin >> g[r][c], dist[r][c] = INF;
        }
        // FOR(r,n) { FOR(c,m) cout << g[r][c] << ' '; cout << endl;}
        set<pair<int,ii>> st;
        st.insert({g[0][0],{0,0}});
        dist[0][0] = g[0][0];
        while(!st.empty()){
            r = st.begin()->se.fi, c = st.begin()->se.se, d = st.begin()->fi;
            st.erase(st.begin());
            // cout << r << ' ' << c << ' ' << d << ' ' << dist[r][c] << endl;
            // if(d > dist[r][c]) continue;
            FOR(k, 4){
                nr = r + dir[k], nc = c+ dir[k+1];
                if(0 <= nr && nr < n && 0 <= nc && nc < m && dist[r][c] + g[nr][nc] < dist[nr][nc]){
                    st.erase({dist[nr][nc], {nr,nc}});
                    dist[nr][nc] = dist[r][c] + g[nr][nc];
                    st.insert({dist[nr][nc], {nr,nc}});
                }
            }
        }
        // FOR(r,n) { FOR(c,m) cout << dist[r][c] << ' '; cout << endl;}
        cout << dist[n-1][m-1] << endl;
    }

}