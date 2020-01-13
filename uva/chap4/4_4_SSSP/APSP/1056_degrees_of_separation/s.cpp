#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

const int P = 50;
const int INF = 51;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define DEBUG
int p,r,order, res,z;
unordered_map<string,int> idx;
int g[P][P];
string names[P], a,b;
void warshal(){
    FOR(k, p) FOR(u,p) FOR(v, p) g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
}
int main(){
    z = 1;
    while(cin >> p >> r, p || r){
        FOR(i,p) FOR(j,p) g[i][j] = INF;
        idx.clear();
        order = 0;
        FOR(z, r){
            cin >> a >> b;
            if(!idx.count(a)) idx[a] = order, names[order++] = a;
            if(!idx.count(b)) idx[b] = order, names[order++] = b;
            g[ idx[a] ][ idx[b] ] = 1;
            g[ idx[b] ][ idx[a] ] = 1;
        }

        warshal();
        #ifndef DEBUG
        FOR(i,p) cout << names[i] << ' ';
        cout << endl;

        FOR(i,p) { FOR(j,p) cout << g[i][j] << ' '; cout << endl;}
        #endif
        
        res = -1;
        FOR(i,p)FOR(j,p) if(i != j) {
            if(g[i][j] == INF) {res = -1; break;}
            res = max(res, g[i][j]);
        }
        cout << "Network " << z << ": ";
        if(res != -1)  cout << res << endl;
        else cout << "DISCONNECTED" << endl;
        cout << endl;
        ++z;
    }
}