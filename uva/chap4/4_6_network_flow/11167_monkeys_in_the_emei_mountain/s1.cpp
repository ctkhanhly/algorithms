#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define L 0
#define R 1
#define pb push_back
#define fi first
#define se second

const int V = 350;//302
const int E = 3*1e4;
const int N = 100;
const int INF = 51000;
int n, m, cap,a,b, s,t, elast[V], epar[E], ecap[E], tail[E], vid, eid;
int drinkTime[N][2], elapse,q[V], dist[V], front,back, drunkTot, needDrink,z,drunk,intv[250];
set<int> intervals;
set<int>:: iterator lo, hi,it;
vector<ii> visits,ans;
unordered_map<int,int> slots;
void addEdge(int u, int v, int w1, int w2){
    ecap[eid] = w1, epar[eid] = elast[u], elast[u] = eid, tail[eid++] = v;
    ecap[eid] = w2, epar[eid] = elast[v], elast[v] = eid, tail[eid++] = u;
}

bool bfs(){
    front = back = 0;
    FOR(i, vid) dist[i] = V;
    q[back++] = s;
    int u,v;
    while(front < back){
        u = q[front++];
        for(int i = elast[u]; i != -1; i = epar[i]){
            v = tail[i];
            if(ecap[i] > 0 && dist[v] == INF){
                dist[v] = dist[u] + 1;
                q[back++] = v;
            }
        }
    }
    return dist[t] < INF;
}

int dfs(int u, int f){
    if(f == 0 || u == t) return f;
    int bflow = 0;
    for(int i = elast[u]; i != -1; i = epar[i]){
        int v = tail[i];
        if(ecap[i] > 0){
            int nbf = dfs(v, min(f, ecap[i]));
            ecap[i] -= nbf;
            ecap[i^1] += nbf;
            bflow += nbf;
            if(nbf == 0) break;
        }
    }
    return bflow;
}
void solve(){
    drunkTot = 0;
    while(bfs()){
        drunkTot += dfs(s, INF);
    }
}
void print(){
    int v,start, left, right;
    FOR(i,n){
        visits.clear();
        for(int i = elast[i]; i != -1; i = epar[i]){
            v = tail[i];
            if(v != s){
                drunk = ecap[i+1];
                it = intervals.begin() + v-n-2;
                start = *it;
                elapse = *(it+1) -(*it);
                if(drunk == 0) continue;
                while(drunk > 0){
                    left = slots[start], right = min(left+drunk, elapse);
                    drunk -= (right-left);
                    slots[start] = right == len ? 0 : right;
                    visits.pb({left, right});
                }
            }
        }
        sort(visits.begin(), visits.end());
        ans.clear();
        FOR(i, visits.size()){
            a = visits[i].fi, b = visits[i].se;
            //merging intervals
            while(i+1 < visits.size() && visits[i+1].fi == b){
                b = visits[i+1].se;
                ++i;
            }
            ans.pb({a,b});
        }
        printf("%d ", ans.size());
        //happy final result
        FOR(i, ans.size()){
            if(i) printf(" ");
            printf("(%d,%d)", ans[i].fi, ans[i].se);
        }
        puts("");
    }
}
int main(){
    z = 1;
    while(scanf("%d %d", &n, &m) == 2){
        vid = eid = s = 0;
        t = ++vid, ++vid;
        intervals.clear();
        FOR(v, V) elast[v] = -1;
        needDrink = 0;
        //graph modeling 
        FOR(i,n) {
            scanf("%d %d %d", &cap, drinkTime[i], drinkTime[i]+1), addEdge(s, i+2, cap,0);
            needDrink += cap;
            intervals.insert(drinkTime[i][L]);
            intervals.insert(drinkTime[i][R]);
        }
        FOR(i,n){
            lo = intervals.lower_bound(drinkTime[i][L]);
            hi = intervals.upper_bound(drinkTime[i][R]);
            while(lo != hi && lo+1 != intervals.end()){//last item is not in the vertices
                elapse = *(lo+1) - *lo;
                addEdge(i+2, lo - intervals.begin(), elapse, 0);
            }
        }
        for(it = intervals.begin(); (it+1) != intervals.end(); ++it){
            elapse = *(it+1) - *it;
            addEdge(it - intervals.begin(), t, m*elapse);
        }   
        vid = 2+ n + intervals.size();
        //solve
        solve();
        slots.clear();
        printf("Case %d: ", z);
        if(drunkTot == needDrink){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}