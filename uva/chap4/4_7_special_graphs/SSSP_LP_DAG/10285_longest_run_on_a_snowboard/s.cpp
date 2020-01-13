#include <iostream>
#include <string>
using namespace std;


//AC
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 100;
int n,m,T,g[N][N],back,dist[N][N],res;
ii st[10100];
bool visited[N][N];
int dir[] = {0,1,0,-1,0};
string s;
void dfs(int r, int c){
    FOR(k,4){
        int i = r + dir[k], j = c + dir[k+1];
        if(0<= i && i < n && 0 <= j && j < m && !visited[i][j] && g[i][j] < g[r][c]){
            visited[i][j] = 1;
            dfs(i,j);
        }  
    }
    st[back++] = {r,c};
}
int main(){
    cin >> T;
    FOR(z,T){
        cin >> s >> n >> m;
        FOR(i,n) FOR(j,m) cin >> g[i][j], visited[i][j] = 0,dist[i][j] = 1;
        back = 0;
        FOR(i,n) FOR(j,m) if(!visited[i][j]) visited[i][j] = 1, dfs(i,j);
        --back;
        int r,c,i,j;
        res = 1;
        while(back >= 0){
            r = st[back].fi, c = st[back--].se;
            FOR(k,4){
                i = r + dir[k], j = c + dir[k+1];
                if(0<= i && i < n && 0 <= j && j < m && g[i][j] < g[r][c]){
                    dist[i][j] = max(dist[i][j], dist[r][c] + 1);
                    res = max(res, dist[i][j]);
                } 
            }
        }
        printf("%s: %d\n", s.c_str(), res);
    }
}