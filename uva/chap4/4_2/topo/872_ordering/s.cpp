#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

//AC
typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i= 0; i < (int)n; ++i)
#define pb push_back
#define DEBUG

typedef enum{ UNVISITED, EXPLORED, VISITED} State;
const int V = 20;
int T,i, N;
State status[V];
string line;
int g[V][V];
char c1,c2;
unordered_map<char, int> toInt;
char elems[V];
bool noAns;
vi topo;
int incom[V];
bool isCycle(int u){
    status[u] = EXPLORED;
    FOR(v,N){
       if(g[u][v]) {
           if(status[v] == EXPLORED) return true;
           else if(status[v] == UNVISITED) if(isCycle(v)) return true;
       }
    }
    status[u] = VISITED;
    return false;
}
//300*V*V^2= 300*20^3= 300*8000= 24 00 000
void topoSort(){
    bool last = true;
    FOR(u, N){
        if(incom[u] == 0 && status[u] == UNVISITED){
            status[u] = VISITED;
            FOR(v, N) if(g[u][v])--incom[v];
            topo.push_back(u);
            topoSort();
            FOR(v, N) if(g[u][v]) ++incom[v];
            topo.pop_back();
            status[u] = UNVISITED;
            last = false;
        }
    }
    if(last){
        FOR(i, topo.size()) {
            cout << elems[ topo[i] ];
            if(i < topo.size()-1) cout << ' ';
            else cout << endl;
        }
    }
}
void init(){
    FOR(i,V) incom[i]  = 0;
    getline(cin,line);
    i = 0;
    for(char c : line){
        if('A' <= c && c <= 'Z') toInt[c] = i, elems[i++] = c;
    }

    N = i;

    FOR(i,N) FOR(j,N) g[i][j] = 0;
    FOR(i, N) status[i] = UNVISITED;
    noAns = false;

    getline(cin, line);
    for(i = 0; i < line.length(); i+=4){
        c1 =  line[i], c2 = line[i+2];
        g[ toInt[c1] ][ toInt[c2] ] = 1;
        ++incom[ toInt[c2] ];
    }
    // cout << line << endl;
    #ifndef DEBUG
    FOR(i,N) {FOR(j, N) cout << g[i][j] << ' '; cout << endl;}
    cout << endl;
    #endif

    noAns = false;
    FOR(i, N) status[i] = UNVISITED;// all possible start- not greater than anyone 
    FOR(i, N){
        if(status[i] == UNVISITED){
            if(isCycle(i)) {noAns = true; break;}
        }
    }
}
int main(){
    cin >> T;
    cin.ignore();
    getline(cin,line);
    FOR(z,T){
        if(z) cout << endl;
        init();
        FOR(i, N) status[i] = UNVISITED;
        if(noAns) cout << "NO\n";
        else topoSort();
        // topoSort();
        // if(noAns) cout << "NO\n";
        getline(cin,line);
    }
}