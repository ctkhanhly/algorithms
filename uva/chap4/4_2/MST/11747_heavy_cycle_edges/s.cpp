#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define f first
#define s second
#define pb push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<list<ii>> vlii;
const int N = 1000;

int m,n,u,v,w;
bool taken[N];
priority_queue<ii> pq;
vector<list<ii>> adjList;
vi res;

void process(int u){
    taken[u] = true;
    for(auto it = adjList[u].begin(); it != adjList[u].end(); ++it){
        v = it->s;
        if(!taken[v]){
            pq.push({-it->f, -v});
        }
    }
}
int main(){
    while(cin >> n >> m, m + n){
        adjList.clear();
        res.clear();
        adjList = vlii(n);
        FOR(z, m){
            cin >> u >> v >> w;
            adjList[u].pb({w, v});
            adjList[v].pb({w, u});
        }
        FOR(i,n) taken[i] = false;
        process(0);
        while(!pq.empty()){
            ii next = pq.top();
            pq.pop();
            u = -next.s, w = -next.f;
            if(!taken[u]) process(u);
            else res.pb(w);
        }
        if(res.empty())  cout << "forest" << endl;
        else{
            FOR(j, res.size())  {cout << res[j]; if(j < res.size()-1) cout << ' ';}
            cout << endl; 
        }
    }
}

