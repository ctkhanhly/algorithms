#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define DEBUG
const int N = 25;
int n,m,order,c, discCnt, numCC;
unordered_map<string, int> idx;

string A,B;
stack<int> st;
int disc[N];
string names[N];
int low[N];
bool explored[N];
vi g[N];
void printSCCs(int u){
    explored[u] = 1;
    disc[u] = low[u] = discCnt++;
    st.push(u);
    #ifndef DEBUG
    cout << names[u] << endl;
    #endif
    FOR(i, g[u].size()){
        int v = g[u][i];//global variable killed me here====> when coming back v has changed so explored is wrong
        if(disc[v] == -1) printSCCs(v);
        if(explored[v]) low[u] = min(low[u], low[v]);
        //back edge, when this back edge comes back
        //it updates low of all parents until it sees the root
        //at which point low[u] = disc[u] = low of all nodes SCC rooted by u
        
    }
    if(disc[u] == low[u]){
        while(1){
            // k = st->top(); st->pop(); explored[k] = 0;
            int k = st.top(); 
            st.pop(); 
            explored[k] = 0;
            cout << names[k];
            if(u == k) break;
            else cout << ", ";
        }
        cout << endl;
    }

}
int main(){
    c = 1;
    while(cin >> n >> m, n+m){
        if(c) cout << endl;
        FOR(i,n) g[i].clear();
        idx.clear();
        order = 0;
        discCnt = 0;
        FOR(i, m) {
            cin >> A >> B;
            if(!idx.count(A)) idx[ A ] = order, names [order++] = A;
            if(!idx.count(B)) idx[ B ] = order, names [order++] = B;
            g[ idx[A] ].pb( idx[B] );
            #ifndef DEBUG
            cout << A << ' ' << B << ' ' << idx[A] << ' ' << idx[B] << endl;
            #endif
        }
        #ifndef DEBUG
        cout << order << endl;
        FOR(i,n) { cout << names[i] << ' ' ; FOR(j, g[i].size()) cout << names[g[i][j]] << ' '; cout << endl;}
        // for(auto it = idx.begin(); it != idx.end(); ++it) cout << it->first << ' ' << it->second << endl;
        // FOR(i,n) { cout << i << ' '; for(auto it = g[u].begin(); it != g[u].end(); ++it) cout << *it << ' '; cout << endl;}
        #endif
        // st = new stack<int>();
        st = stack<int>();
        FOR(i, n) { disc[i] = -1, low[i] = 0, explored[i] = 0;}
        cout << "Calling circles for data set " << c << ":\n";
        numCC = 0;
        FOR(i,n){
            if(disc[i] == -1) printSCCs(i);
        }

        #ifndef DEBUG
        cout << numCC << endl;
        #endif
        ++c;
    }
}