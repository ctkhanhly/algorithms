#include <iostream>
#include <queue>
// #include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first 
#define se second

const int SIDE = 1001;
int R, C, rows, cols, r,c, sr,sc, er,ec, clk,sz;
int g[SIDE][SIDE];
int dir[5] = {0,1,0,-1,0};
struct D{
    int r,c,d;
};
D u;

int main(){

    while(cin >> R >> C, R+C){
        FOR(i,R) FOR(j, C) g[i][j] = 1;
        cin >> rows;
        FOR(z, rows){
            cin >> r;
            cin >> cols;
            FOR(p, cols) cin >> c, g[r][c] = 0;
        }
        cin >> sr >> sc >> er >> ec;
        // cout << "finished processsing\n";
        clk = 0;
        g[sr][sc] = 0;
        if(!(sr == er && sc == ec)){
            queue<D> q;
            q.push({sr,sc,0});
            while(!q.empty()){
                sz = q.size();
                while(sz--){
                    u = q.front(), q.pop();
                    FOR(k, 4){
                        r = u.r + dir[k], c = u.c + dir[k+1];
                        if(r == er && c == ec) { clk = u.d +1; break;}
                        if(0<= r && r < R && 0 <= c && c < C && g[r][c]){
                            q.push({r,c,u.d+1}), g[r][c] = 0;
                        }
                    } 
                }
            }
        }
        cout << clk << "\n";
    }
}