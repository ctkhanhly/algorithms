#include <iostream>
#include <queue>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

//AC
typedef pair<int,int> ii;
#define FOR(i, n) for(int i =0; i < (int)n; ++i)
#define  f first
#define  se second

const int MALLS = 2;
const int SIDE = 2001;
int T, p, a,s,x, y, m, n, sz,dist;
int g[SIDE][SIDE];
int dir[5] = {0,1,0,-1,0};
struct D{
    int y, x, d;
};
queue<D> q;
D u,v;
int BFS(){
    dist = 0;
    while(!q.empty()){
        sz = q.size();
        while(sz--){
            u = q.front(), q.pop();
            // cout << u.f << ' ' << u.se << endl;
            // if(g[u.y][u.x] == 2) return u.d;
            FOR(k, 4){
                a = u.y+  dir[k], s =  u.x + dir[k+1];
                if(0<= a && a <= m && 0 <= s && s <= n && (g[a][s] == -1 || g[a][s] == 2)){
                    // cout << u.f << ' ' << u.se << ' ' << a << ' ' << s << endl;
                    // if(g[a][s] == 2) return u.d+1;
                    if(g[a][s] == 2) return dist+1;
                    q.push({a,s, u.d+1}), g[a][s] = 0; 
                }
            }
        }
        ++dist;
    }
    return -1;
}
int main(){
    while(cin >> p, p){
        FOR(i, SIDE) FOR(j, SIDE) g[i][j] = -1; 
        x = y = SIDE;
        m = n = 0;
        q = queue<D>();
        FOR(l, p){
            cin >> a >> s;
            g[a][s] = 0;
            m = max(m, a), n = max(n, s);
            q.push({a,s,0});
        }
        cin >> p;
        FOR(l, p){
            cin >> a >> s;
            m = max(m, a), n = max(n, s);
            g[a][s] = 2;
        }
        // FOR(i, m+1) { FOR(j, n+1) cout << g[i][j] << ' '; cout << endl; }
        // cout << m << ' ' << n << endl;
        // cout << q.size() << endl;
        cout << BFS() << "\n";
    }
    
}