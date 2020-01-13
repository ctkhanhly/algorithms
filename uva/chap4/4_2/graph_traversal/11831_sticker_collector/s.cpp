#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

#define n 0
#define e 1
#define s 2
#define w 3
#define L -1
#define R 1
#define FOR(i, n) for(int i= 0; i < (int)n; ++i)
typedef pair<int,int> ii;

const int MX_N = 101;
const int MX_S = 5*1e4+1;
char g[MX_N][MX_N],ins[MX_S];
int T,N, M, S, ans,x,y,k,nx,ny, lame;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
char start;

int main(){
    while(cin >> N >> M >> S && N && M && S){
        //if(g[i][j] != '.' || g[i][j] != '#' || g[i][j] != '*')
        FOR(i,N) FOR(j, M)
        // { scanf("%c", &g[i][j]);
        // cout << g[i][j];
        {   cin >> g[i][j];
            if('A' < g[i][j] && g[i][j] < 'Z') start = g[i][j],x=i,y=j;}
        //  FOR(i,N) {FOR(j, M) cout << g[i][j]; cout << endl;}
        //  cout << N << ' ' << M << ' ' << start << ' ' << x << ' ' << y << endl;
        scanf("%s", ins);
        // cout << string(ins) << endl;
        ans = 0;
        // k = start == 'N' ? (n : start == 'S' ? s : (start == 'L' ? w : e));
        if(start == 'N') k = n;
        else if (start == 'S') k = s;
        else if(start == 'L') k = e;
        else k = w;
        //DEF
        FOR(i, S) {
            if(ins[i] == 'D') k+=R; else if(ins[i] == 'E') k+=L; 
            else {
                k = k%4;
                if(k < 0) k= (k+4)%4;
                nx= x+dr[k], ny = y+dc[k];
                if(0<= nx && nx < N && 0<= ny && ny < M){
                    // cout << k << ' ' << x << ' ' << y << ' ' << nx << ' ' << ny << ' ' << g[nx][ny]<< endl;
                    if(g[nx][ny] == '*') ++ans, g[nx][ny] = '.';
                    if(g[nx][ny] != '#') {
                        x = nx, y = ny;
                    }
                } 
            }
        }
        
        cout << ans << endl;
        // if(u == T-1) scanf("%d %d %d", &lame, &lame, &lame);
    }
    
}