#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <numeric>
using namespace std;



//AC
typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define B 1
#define W 0
const int N = 100;
int m,n,k,u,v,nei,res;
vi g[N];
bool color[N], turnBlack;

vi black, trace;
//T(n) = 2T(n-1) + O(d(i)) = 2*(n-1) + 4*(n-2) +...+ 2^n *1 < n*2^n ~~~bad
void backtrack(int s){
    if(s == n) {
        if(trace.size() > res){
            res = trace.size();
            black = trace;
        }
        return;
    }
    color[s] = B;
    trace.pb(s);
    turnBlack = true; 
    FOR(i, g[s].size()){
        if(color[ g[s][i] ] == B){
            turnBlack = false;
            break;
        }
    }
    if(turnBlack) backtrack(s+1);
    trace.pop_back();
    color[s] = W;
    backtrack(s+1);
}
int main(){
    scanf("%d", &m);
    FOR(z,m){
        scanf("%d %d", &n, &k);
        black.clear(), trace.clear();
        FOR(i,n) g[i].clear(), color[i] = W;
        FOR(o,k){
            scanf("%d %d", &u, &v);
            g[--u].pb(--v);
            g[v].pb(u);
        }
        res = 0;
        backtrack(0);
        // if(z) cout << endl;
        cout << res << endl;
        FOR(i, black.size()) {if(i) cout << ' '; cout << black[i]+1;}
        cout << endl;
    }
}