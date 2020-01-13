#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> ii;

const int N = 101;
const int INF = INT_MAX;
int dist[N];
int c, n, a,b,E, t, T, M, totTi, mices;
vector<ii> edges[N];

int main(){

    cin >> c;
    FOR(z, c){
        cin >> n >> E >> T;
        FOR(i, n) edges[i+1].clear(), dist[i+1] = INF;
        cin >> M;
        FOR(l, M){
            cin >> a >> b >> t;
            edges[b].pb({t,a});
        }
        set<ii> st;
        st.insert({0, E});
        dist[E] = 0;
        mices = 0;
        while(!st.empty()){
            a = st.begin()->se, totTi = st.begin()->fi;
            st.erase(st.begin());
            // cout << a << endl;
            //else must have been ==, < means already processed
            if(totTi > dist[a] || dist[a] > T) continue;
            FOR(i, edges[a].size()){
                b = edges[a][i].se, t = edges[a][i].fi;
                if(dist[a] + t < dist[b]){
                    st.erase({dist[b], b});
                    dist[b] = dist[a] + t;
                    st.insert({dist[b], b});
                }
            }
        }
        FOR(i,n){
            if(dist[i+1] <= T) ++mices;
        }
        cout << mices << endl;
        if(z < c-1) cout << endl;
    }
}