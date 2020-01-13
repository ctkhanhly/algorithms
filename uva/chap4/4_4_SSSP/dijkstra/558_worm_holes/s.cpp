#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//AC
typedef vector<int> vi;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
#define s 0
// #define DEBUG

const int N = 1000, M = 2000;
const int INF = 2000005;

int n, m, x, y,t,c,v;
vector<ii> wormH[N];
bool hasNegCyc;
int dist[N];
int main(){
    cin >> c;
    FOR(z,c){
        cin >> n >> m;
        FOR(i,n) dist[i] = INF, wormH[i].clear();
        // FOR(i,n) cout << dist[i] << ' '; cout << endl;
        FOR(q, m){
            cin >> x >> y >> t;
            wormH[x].pb({t,y});
            // wormH[y].pb({t,x});
        }
        hasNegCyc = false;
        dist[s] = 0;
        FOR(i, n){
            FOR(u, n)
                FOR(j, wormH[u].size()){
                    v = wormH[u][j].se, t = wormH[u][j].fi;
                    dist[v] = min(dist[v], dist[u] + t); 
                }
        }
            
        FOR(i, n)
            FOR(u, n)
                FOR(j, wormH[u].size()){
                    v = wormH[u][j].se, t = wormH[u][j].fi;
                    //cout << u << ' '  <<   v << endl; 
                    if(dist[v] > dist[u] + t) { hasNegCyc = true; break;}
                }
                    
        // FOR(i,n) cout << dist[i] << ' '; cout << endl;
        if(hasNegCyc) cout << "possible\n";
        else cout << "not possible\n";
                   
               
    }
}