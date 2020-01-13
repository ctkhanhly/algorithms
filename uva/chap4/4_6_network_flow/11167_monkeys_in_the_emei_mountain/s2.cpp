#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


//AC
typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define L 0
#define R 1
#define pb push_back
#define fi first
#define se second

const int V = 350;//302
const int E = 30000;
const int N = 100;
const int INF = 51000;
int n, m, cap,a,b, s,t, elast[V], epar[E], ecap[E], tail[E], vid, eid,idx;
int drinkTime[N][2],q[V],slots[300], dist[V], elapse, front,back, drunkTot, needDrink,z,drunk,sz;
set<int> intervals;
set<int>:: iterator it;
int* lo, *hi;
vector<ii> visits,ans;
unordered_map<int,int> lastSlot;
void addEdge(int u, int v, int w1, int w2){
    ecap[eid] = w1, epar[eid] = elast[u], elast[u] = eid, tail[eid++] = v;
    ecap[eid] = w2, epar[eid] = elast[v], elast[v] = eid, tail[eid++] = u;
}

bool bfs(){
    front = back = 0; 
    FOR(i, vid) dist[i] = V;
    q[back++] = s;
    dist[s] = 0;
    int u,v;
    while(front < back){
        u = q[front++];
        for(int i = elast[u]; i != -1; i = epar[i]){
            v = tail[i];
            if(ecap[i] > 0 && dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                q[back++] = v;
            }
        }
    }
    return dist[t] < V;
}

int dfs(int u, int f){
    if(f == 0 || u == t) return f;
    int bflow = 0;
    for(int i = elast[u]; i != -1; i = epar[i]){
        int v = tail[i];
        if(ecap[i] > 0 && dist[v] == dist[u] + 1 ){
            int nbf = dfs(v, min(f, ecap[i]));
            ecap[i] -= nbf;
            ecap[i^1] += nbf;
            f-= nbf;
            bflow += nbf;
            if(f == 0) break;
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
    lastSlot.clear();
    FOR(i,n){
        visits.clear();
        for(int j = elast[i+2]; j != -1; j = epar[j]){
            v = tail[j];
            if(v != s){
                drunk = ecap[j+1];
                idx = v - n - 2;
                start = slots[idx];
                elapse = slots[idx+1] - slots[idx];
                if(drunk == 0) continue;
                while(drunk > 0){
                    left = lastSlot[start], right = min(left+drunk, elapse);
                    drunk -= (right-left);
                    lastSlot[start] = right == elapse ? 0 : right;
                    visits.pb({left+start, right+start});
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
        printf("%d ", (int)ans.size());
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
    while(scanf("%d", &n) == 1 && n){
        scanf("%d", &m);
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
        sz = 0;
        for(it = intervals.begin(); it != intervals.end(); ++it) slots[sz++] = *it;
        FOR(i,n){
            lo = lower_bound(slots, slots + sz, drinkTime[i][L]);
            idx = lo - slots;
            while(idx+1 < sz && slots[idx+1] <= drinkTime[i][R]){
                addEdge(i+2, idx+n+2, slots[idx+1]-slots[idx],0);
                ++idx;
            }
        }
        FOR(i, sz-1){
            elapse = slots[i+1] - slots[i];
            addEdge(i+n+2,t, m*elapse,0);
        }
        vid = 2+ n + sz-1;
        solve();
        printf("Case %d: ", z);
        if(drunkTot == needDrink){
            printf("Yes\n");
            print();
        }
        else printf("No\n");
        ++z;
    }
}