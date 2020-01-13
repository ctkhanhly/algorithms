#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;


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
    #ifndef DEBUG
    // cout << "DFSing " << u  << ' ' <<  disc[u] << endl;
    #endif
    // if(!hadSCC){
        explored[u] = 1;
        st.push(u);
        low[u] = disc[u] = ++discCnter;
        FOR(v, n){
            if(g[u][v] && disc[v] == -1) tarjanSCC(v);
            if(explored[v]) low[u] = min(low[u], low[v]);
        }
        if(disc[u] == low[u]){
            // vi SCC;
            while(!st.empty()){
                vertex = st.top(), st.pop();
                explored[vertex] = 0;
                // SCC.pb(vertex);
                // subDict.pb(vertex);
                SCCs[SCCnum].pb(vertex);
                #ifndef DEBUG
                cout << dic[vertex] << ' ';
                #endif
                if(vertex == u) break;
            }
            
            // if(!hadSCC) hadSCC = true;//, subDict = SCC;
            #ifndef DEBUG
            cout << endl;
            cout << SCCnum << endl;
            #endif
            ++SCCnum;
        }
    // }
    
}
void dfs(int u){
    explored[u] = 1;
    res.pb( dic[u] );
    FOR(v, n) if(g[u][v] && !explored[v]) dfs(v);
}
//if dictionary only has 1 word => define it
//a word cannot define itself ever ever
int main(){
    r = 0;
    while(cin >> n, n){
        // if(r) cout << endl;
        cin.ignore();
        k = 0;
        FOR(i,n) explored[i] = 0, disc[i] = -1, low[i] = -1, SCCs[i].clear();
        FOR(i,n) FOR(j, n) g[i][j] = 0;
        res.clear(), idx.clear();

        FOR(z,n){
            #ifndef DEBUG
                cout << z << endl;
            #endif 
            getline(cin, line);
            // cout << line << endl;
            word = "";
            t = 0;
            start = 0;
            for(char c : line){
                #ifndef DEBUG
                    if(c == '\n') cout << "EOL\n";
                #endif 
                if(c != ' ') word += c;
                else {
                    // cout << word << endl;
                    if(!idx.count(word)) idx[word] = k, dic[k++] = word;
                    if(t == 0) start = idx[word];
                    else g[start][ idx[word] ] = 1;
                    #ifndef DEBUG
                        cout << idx[word] << ' '<< start << ' ' << word << endl;
                    #endif 
                    word = "";
                    ++t;
                }
            }
            if(word != " "){
                if(!idx.count(word)) idx[word] = k, dic[k++] = word;
                g[start][ idx[word] ] = 1;
            }
           
            #ifndef DEBUG
                cout << idx[word] << ' ' << start << ' '  << word << endl;
                cout << z << ' ' << n << ' ' << line << endl;
            #endif 
        }
        
        #ifndef DEBUG
            FOR(i,n) { FOR(j,n) cout << g[i][j] << ' '; cout << endl; } 
            cout << "here\n";
        #endif

        discCnter = SCCnum = 0;
        FOR(i, n) if(disc[i] == -1) tarjanSCC(i);

        #ifndef DEBUG
        // cout << "finished DFS\n";
        #endif

        // FOR(i,n) explored[i] = false;
        // FOR(i, subDict.size()) explored[i] = true;
        // t = subDict.size();
        #ifndef DEBUG
            // cout << subDict.size() << endl;
            // FOR(i, subDict.size()) cout << subDict[i] << ' ';
            // cout << endl;
        #endif
        // FOR(i,t){
        //     int u = subDict[i];
        //     FOR(v, n){
        //         if(g[u][v] && ! explored[v]) subDict.pb(v), explored[v] = true;
        //     }
        // }
        // FOR(i, subDict.size()) res.pb(dic[ subDict[i] ]);
        FOR(i, n) explored[i] = false;
        //print out all SCC > 0 and the single SCC that is the right of this SCC in topo order
        //=> needs dfs for these single ones
        FOR(i,SCCnum) if(SCCs[i].size() > 0 && !explored[ SCCs[i][0] ]) dfs(SCCs[i][0]);

        sort(res.begin(), res.end());
        cout << res.size() << endl;
        FOR(i, res.size()) { cout << res[i]; if(i < res.size()) cout << ' ';} 
        cout << endl;
        r++;
    }
    
}   

/*
5
aue oizer piqoi oizer
doy oizer hweqlo hweqlo
hweqlo piqoi aue
oizer piqoi
piqoi aue aue
12
A E
E D
D C
C B
A F
E G
D H
F G
G F
H F
M N
N O
O P
P C
0
*/