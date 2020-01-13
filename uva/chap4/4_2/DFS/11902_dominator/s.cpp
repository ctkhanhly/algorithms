#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second
#define pb push_back
#define  DEBUG

int T,n;
string s;
const int N = 100;
bool fromS[N];
bool woX[N];
int g[N][N];
bool res[N][N];
void dfs(int u){
    // cout << "dfs1 " << u << endl;
    FOR(v,n){
        if(g[u][v] && !fromS[v]) fromS[v] = true, dfs(v);
    }
}
void dfsX(int u, int x){
    // cout << "dfs2 " << u << endl;
    // cout << u << ' ';
    if(u == x) return;
    FOR(v,n){
        if(v == x) continue;
        if(g[u][v] && !woX[v]) woX[v] = true, dfsX(v,x);
    }
}
void printLine(){
    cout << '+';
    // s = string(2*n-1, '-');
    // cout << s;
    FOR(i, 2*n-1) cout << '-';
    cout << "+\n";
}
int main(){
    // n = 4;
    // printLine();
    cin >> T;
    FOR(z,T){
        cin >> n;
        FOR(i, n) { FOR(j, n) cin >> g[i][j], res[i][j] = true;}
        
        memset(fromS,0, sizeof(fromS));
        fromS[0] = true;
        dfs(0);
        #ifndef DEBUG
        FOR(i,n) {FOR(j,n) cout << res[i][j] << ' '; cout << endl;}
        FOR(i, n) { FOR(j, n) cout << g[i][j] << ' '; cout << endl;}
         FOR(i,n) cout << fromS[i] << ' ';
        cout << endl;
        cout << endl;
        #endif
       
        FOR(i, n){
            memset(woX,0, sizeof(woX));
            // FOR(j,n) woX[j] = 0;

            #ifndef DEBUG
            FOR(j, n) cout << woX[j] << ' ';
            cout << endl;
            #endif

            woX[0] = true;
            dfsX(0,i);

            #ifndef DEBUG
            cout << "at node " << i << ": ";
            
           
            cout << endl;
            FOR(j, n) cout << woX[j] << ' ';
            cout << endl;
            // FOR(j, n) cout << woX[i] << ' ';
            // cout << endl;
            #endif

            FOR(j, n) if(woX[j] || !fromS[j]) res[i][j] = false;//, cout << res[i][j] << ' ';
            // cout << endl;
        }
        res[0][0] = true;

        
        #ifndef DEBUG
        FOR(i,n) {FOR(j,n) cout << res[i][j] << ' '; cout << endl;}
        cout << endl;
         FOR(i, n) { FOR(j, n) cout << g[i][j] << ' '; cout << endl;}
         cout << endl;
        #endif

        cout << "Case " << (z+1) << ":\n";
        printLine();
        // cout << endl;
        FOR(i,n){
            cout << '|';
            FOR(j,n)cout << (res[i][j] ? 'Y': 'N') << '|';
            cout << endl;
            printLine();
            // if(!(z  == T-1 && i == n-1))cout << endl;
        }
    }
}