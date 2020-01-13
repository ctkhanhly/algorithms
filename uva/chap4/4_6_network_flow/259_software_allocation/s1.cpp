#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define DEBUG
const int V = 38+5;

typedef vector<int> vi;
const int S = 0;
const int T = 37;
const int INF = 10+5;
int res[V][V], mf, f,a,c,u, appNum;
char alloc[10];
string line;
vi p(V);
bool chosen;
void process(){
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == ' '){
            ++i;
            while(i < line.size()-1) c = line[i]-'0' + 27, res[a][c] = INF, ++i;
        }
        else if(isdigit(line[i])){
            res[S][a] = line[i] -'0';
            appNum += res[S][a];
        }
        else a = line[i]-'A'+1;
    }
}
void augment(int v, int minEdge){
    if(v == S) f = minEdge;
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
        if(27 <= v && v <= 36) c = v;
        if(1<=v && v <= 26) a = v;
    }
}
int main(){
    while(1){
        appNum = 0;
        FOR(i, V) FOR(j, V) res[i][j] = 0;
        while(getline(cin, line) && !line.empty()){
            process();
        }
        if(appNum == 0) break;
        FOR(i,10) c = i+27, res[c][T] = 1;

        #ifndef DEBUG
        cout << "Residual graph construction\n";
        FOR(i,V) {FOR(j,V) cout << res[i][j] << ' '; cout << endl;}
        #endif

        FOR(i,10) alloc[i] = '*';
        mf = 0;
        while(1){
            vi dist(V, INF);
            f = 0;
            p.assign(V, -1);
            queue<int> q;
            q.push(S);
            dist[S] = 0;
            while(!q.empty()){
                u = q.front();
                q.pop();
                if(u == T) break;
                FOR(v, V){
                    // cout << res[u][v] << endl;
                    if(res[u][v] > 0 && dist[v] == INF){
                        dist[v] = dist[u] +1;
                        p[v] = u;
                        q.push(v);
                    }
                }
            }
            
            augment(T, INF);
            if(f == 0) break;
            #ifndef DEBUG
            cout << "Residual each augmentation\n";
            FOR(i,V) {FOR(j,V) cout << res[i][j] << ' '; cout << endl;}
            #endif
            alloc[c-27] = a-1 +'A';
            mf += f;
        }


        if(mf == appNum){
            FOR(i, 10) {
                chosen = false;
                FOR(j,26){
                    if(res[i+27][j+1] ==1) { printf("%c", 'A'+j); chosen = true; break; }
                }
                if(!chosen) cout << '_';
            }
            cout << endl;
        }
        else cout << "!\n";
        
    }
    
}