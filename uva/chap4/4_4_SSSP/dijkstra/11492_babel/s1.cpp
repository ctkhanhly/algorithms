#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

//AC
typedef vector<int> vi;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
#define DEBUG

const int M = 2002;
const int INF = 100005;
int m, s, t, lacnt, wo, la, len, vla,nwo, ans,c,e,l1,l2,l3,l4;
string O,D, I1,I2, P;

vector<ii> g[M];
ii words[M];
int dist[M];
int cost[M];
char letter[M];

void dijkstra(){
    set<ii> st;
    st.insert({0,0});
    dist[0] = 0;//g[0] has all the possible start, g[M-1] has all the possible ends
    while(!st.empty()){
        len = st.begin()->fi, wo = st.begin()->se;
        st.erase(st.begin());
        // cout << wo << ' ' << len << endl;
        FOR(i, g[wo].size()){
            nwo = g[wo][i].se, c = g[wo][i].fi;
            if(dist[wo ] + c < dist[nwo]){
                st.erase({dist[nwo], nwo});
                dist[nwo] = dist[wo]+ c;
                st.insert({dist[nwo], nwo});

                // cout << nwo << ' ' << wo << ' ' << c << ' ' << dist[nwo] << endl;
            }
        }
    }
}

void buildGraph(){
    FOR(i,M) g[i].clear(), dist[i] = INF;
    for(int i = 1; i <= m; ++i){
        for(int j = i+1; j <= m; ++j){
            l1 = words[i].fi, l2 = words[i].se, l3 = words[j].fi, l4 = words[j].se;
            if((l1 == l4 || l1 == l3 || l2 ==l3 || l2 == l4) && letter[i] != letter[j]){
                //add 1 word to the list, push in the queue the next possible word
                //g[M-1] terminates with no next word=>final destination
                g[i].pb({cost[i], j});
                g[j].pb({cost[j], i});
            }
        }
    }

    //since there are multiple words that can start and end, 
    //as long as one of them gets updated=> language is satisfied
    //cannot use warshal b/c > 400 V possibly

    // FOR(i, g[s].size()) c = g[s][i].fi, wo = g[s][i].se, g[0].pb({ 0, wo });
    // FOR(i, g[t].size()) c = g[s][i].fi, wo = g[s][i].se, g[ wo ].pb({ c, M-1 });
    //here or above does not matter
    for(int i = 1; i <= m; ++i){
        if(words[i].fi == s || words[i].se == s)
            g[0].pb({0,i});
        if(words[i].fi == t || words[i].se == t)
            g[i].pb({cost[i],M-1});
    }
}
int main(){
    while(cin >> m, m){
        cin >> O >> D;
        unordered_map<string,int> langMap;
        lacnt = 2;
        langMap[O] = s = 0, langMap[D] = t = 1;

        for(int i = 1; i <= m; ++i){

            cin >> I1 >> I2 >> P;
            if(!langMap.count(I1)) langMap[I1] = lacnt++;
            if(!langMap.count(I2)) langMap[I2] = lacnt++;
            cost[i] = P.length();
            letter[i] = P[0];
            words[i] = { langMap[I1], langMap[I2] };

            //do it here=> repeats=> has to do it last!
            // if(I1 == O || I2 == O) g[0].pb({0, i});
            // else if(I1 == D || I2 == D) g[i].pb({cost[i], M-1});

        }
        buildGraph();
        dijkstra();
        if(dist[M-1] != INF) cout << dist[M-1] << endl;
        else cout << "impossivel" << endl;
    }
}