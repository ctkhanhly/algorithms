#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


//AC
#define FOR(i,j,n) for(int (i)=(j); (i) < (n); ++(i))
#define pb push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
const int N = 26;
int T, visited, subTime[N],res,dist[N],q[N],front,back,idx;
vi g[N];
string s;
stack<int>* st;
void dfs(int u){
    visited |= (1<<u);
    FOR(i,0, g[u].size()){
        int v= g[u][i];
        if(!(visited &(1<<v))) dfs(v);
    }
    st->push(u);
}
int main(){
    scanf("%d", &T);
    getline(cin,s);
    getline(cin,s);
    int u,v;
    FOR(z, 0,T){
        FOR(i,0,N) subTime[i] = -1, g[i].clear(), dist[i] = 0;
        while(getline(cin,s) && !s.empty()){
            idx = 0;
            v = s[0]-'A';
            subTime[v] = 0;
            idx = 2;
            while(idx < s.size() && isdigit(s[idx])) subTime[v] = subTime[v]*10 + s[idx++]-'0';
            ++idx;
            if(s.size() <= idx) continue;
            FOR(i,idx, s.size()){
                u = s[i]-'A';
                g[u].pb(v);
            }
        }
        st = new stack<int>();
        visited = 0;
        FOR(i,0,26) if(!(visited & (1<<i)) && subTime[i] != -1) dfs(i);
        res = 0;
        while(!st->empty()){
            u = st->top();
            st->pop();
            if(dist[u] == 0) dist[u] = subTime[u];
            res = max(res, dist[u]);
            FOR(i, 0,g[u].size()){
                v = g[u][i];
                dist[v] = max(dist[v], dist[u]+subTime[v]);
                res = max(res, dist[v]);
            }
        }
        if(z) cout << endl;
        cout << res << endl;
    }
}