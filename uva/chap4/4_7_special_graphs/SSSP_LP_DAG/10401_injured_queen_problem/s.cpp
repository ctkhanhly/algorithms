#include <iostream>
#include <string>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 15;
string s;
int col[N],n, ways[N][N],g[N][N];
int dir[] = {-0,-1,-1,1,-1,0,1,1,0};
bool hasQueenNeighbor(int r, int c){
    if(!(0 <= i && i < n && 0 <= j && j < n && !g[i][j])) return false;
    FOR(k, 8){
        int i = r + dir[k], j = c + dir[k+1];
        if(0 <= i && i < n && 0 <= j && j < n && g[i][j]) return false;
    }
    return true;
}
//15^15
int backtrack(int c){
    int res = 0;
    int i = col[c];
    FOR(r, n){
        if(r == i) continue;
        if(hasQueenNeighbor(r,c)) continue;
        res = 1 + res + backtrack(c+1);
    }
    return res;
}
int main(){
    while(getline(cin,s)){
        n = s.size();
        FOR(i, n) row[i] = 0;
        FOR(i,n) FOR(j,n) ways[i][j] = g[i][j] = 0;
        int r;
        FOR(i,n) {
            if(isdigit(s[i])) r = s[i]-'0', col[i] = r, g[r][c] = 1;
            else r = s[i]-'A'+10, col[i] = r, g[r][c] = 1;
        }
    }
}