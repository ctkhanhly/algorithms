#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <limits.h>
using namespace std;
 
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second
#define pb push_back
#define s 0
#define INF INT_MAX
typedef pair<int,int> ii;
typedef vector<int> vi;

//AC
const int N = 100;
int T[N], n, k, Ti,fl, ans,t,v,u,e, nd,ne;
string floors;
vector<int> edges[6];
vi p[N];
int dist[N][6];
int main(){
    while(cin >> n >> k){
        FOR(i,n) cin >> T[i+1], edges[i+1].clear();
        FOR(i, N) { p[i].clear(); FOR(j,n+1) dist[i][j] = INF;}
        cin.ignore();
        FOR(i,n) {
            getline(cin, floors);
            stringstream ss(floors);
            while( ss >> fl) edges[i+1].pb(fl),p[fl].pb(i+1);
        }
        set<pair<int,ii>> st;
        FOR(i, p[0].size()){
            e = p[0][i];
            st.insert({0,{s, e}});
            dist[s][ e ] = 0;
        }
        ans = -1;
        while(!st.empty()){
            fl = st.begin()->se.fi, e = st.begin()->se.se, t = st.begin()->fi;
            st.erase(st.begin());
            if(fl == k) {ans = t; break;}
            if(t > dist[fl][e]) continue;
            FOR(j,p[fl].size()){
                ne = p[fl][j];
                FOR(i, edges[ ne ].size()){
                    v = edges[ ne ][i];
                    nd = T[ ne ] *abs(v-fl) + dist[fl][e] + (e == ne ? 0 : 60);
                    if( nd < dist[v][ ne ]){
                        st.erase({ dist[v][  ne  ], {v, ne }});
                        dist[v][ne] = nd;
                        st.insert({ dist[v][  ne ], {v, ne }});
                    }
                }
            }
            
        }
        //i can come back to that elevator but has to be on a different floor
        //E = 10^4
        if(ans != -1) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    
}