#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     (int)1e9
#define MAXN    2005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N;
string start, ending;
pair<int, pair<string, string> > words[MAXN];
vii graph[MAXN];
int dist[MAXN];
char letter[MAXN];

void dijkstra()
{
    dist[0] = 0;//0 is a dummy node=>does not matter
    //no other word connect to it
    //only has outbound = start node
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, 0));

    while(!pq.empty())
    {
        ii c = pq.top(); pq.pop();
        int d = c.fi, h = c.se;
        if(d > dist[h]) continue;
        for(int i = 0; i < sz(graph[h]); i++)
        {
            //word 0 to start = 0
            int t = graph[h][i].fi, w = graph[h][i].se;
            if(dist[h] + w < dist[t])
            {
                dist[t] = dist[h] + w;
                pq.push(ii(dist[t], t));
            }
        }
    }
}

void makeGraph()
{
    for(int i = 1; i < N; i++)
        for(int j = i+1; j <= N; j++)
        {
            string w1_1 = words[i].se.fi;
            string w1_2 = words[i].se.se;
            string w2_1 = words[j].se.fi;
            string w2_2 = words[j].se.se;

            //avery word can be next to each other as long as they they share a language 
            //and their initial leters are different
            //does direction of language matter?
            //seems like no.....
            //a graph of connections of words

            if((w1_1 == w2_1 || w1_1 == w2_2 || w1_2 == w2_1 || w1_2 == w2_2) && letter[i] != letter[j]) 
            {
                graph[i].pb(mp(j, words[i].fi));
                graph[j].pb(mp(i, words[j].fi));
            }
        }

    for(int i = 1; i <= N; i++)
    {
        if(words[i].se.fi == start || words[i].se.se == start) 
            graph[0].pb(ii(i, 0));

        //add another dummy ending connection at MAXN    
        //quite a waste since you have to wait for dijkstra to finish all paths
        //instead of as soon as it finds target   

        if(words[i].se.fi == ending || words[i].se.se == ending)
            graph[i].pb(ii(MAXN-1, words[i].fi));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while(cin >> N, N)
    {
        cin >> start >> ending;
        string temp;
        for(int i = 0; i <= N; i++) { graph[i].clear(); dist[i] = INF; }
        graph[MAXN-1].clear(); dist[MAXN-1] = INF;
        for(int i = 1; i <= N; i++)
        {
            cin >> words[i].se.fi >> words[i].se.se >> temp;
            words[i].fi = temp.length();
            letter[i] = temp[0];
        }

        makeGraph();
        dijkstra();

        if(dist[MAXN-1] == INF) printf("impossivel\n");
        else printf("%d\n", dist[MAXN-1]);
    }
    return 0;
}