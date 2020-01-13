#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

//AC

typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
#define DEBUG
const int N = 101;

unordered_map<string,int> idx;
int n, k, disc[N], low[N],t,r;
string dic[N], line, word;
int g[N][N], start, discCnter, vertex,SCCnum;
bool explored[N], hadSCC;
stack<int> st;
vi SCCs[N];
vector<string> res;

void tarjanSCC(int u){
    explored[u] = 1;
    st.push(u);
    low[u] = disc[u] = ++discCnter;
    FOR(v, n){
        if(!g[u][v]) continue;
        if(disc[v] == -1) tarjanSCC(v);
        if(explored[v]) low[u] = min(low[u], low[v]);
    }
    if(disc[u] == low[u]){
        while(!st.empty()){
            vertex = st.top(), st.pop();
            explored[vertex] = 0;
            SCCs[SCCnum].pb(vertex);
            if(vertex == u) break;
        }
        ++SCCnum;
    }
    
}
void dfs(int u){
    explored[u] = 1;
    res.pb( dic[u] );
    FOR(v, n) if(g[u][v] && !explored[v]) dfs(v);
}

int main(){
    r = 0;
    while(cin >> n, n){
        cin.ignore();
        k = 0;
        FOR(i,n) explored[i] = 0, disc[i] = -1, low[i] = -1, SCCs[i].clear();
        FOR(i,n) FOR(j, n) g[i][j] = 0;
        res.clear(), idx.clear();

        FOR(z,n){
            getline(cin, line);
            word = "";
            t = 0;
            start = 0;
            for(char c : line){
                if(c != ' ') word += c;
                else {
                    if(!idx.count(word)) idx[word] = k, dic[k++] = word;
                    if(t == 0) start = idx[word];
                    else g[start][ idx[word] ] = 1;
                    word = "";
                    ++t;
                }
            }
            if(word != " "){
                if(!idx.count(word)) idx[word] = k, dic[k++] = word;
                g[start][ idx[word] ] = 1;
            }
           
        }
        discCnter = SCCnum = 0;
        FOR(i, n) if(disc[i] == -1) tarjanSCC(i);
        FOR(i, n) explored[i] = false;
        FOR(i,SCCnum) if(SCCs[i].size() > 1 && !explored[ SCCs[i][0] ]) dfs(SCCs[i][0]);

        sort(res.begin(), res.end());
        cout << res.size() << endl;
        FOR(i, res.size()) { cout << res[i]; if(i < res.size()-1) cout << ' ';} 
        cout << endl;
        r++;
    }
    
}   
