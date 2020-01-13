#include <iostream>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int INF = INT_MAX;
const int N = 1000;
const int M = 18278;
int T, m,n, ssheet[N+10][N+10];
string formula[N+10][N+10],s;


int dfs(int r, int c){
    if(ssheet[r][c] != INF) return ssheet[r][c];
    // cout << r << ' ' << c << endl;
    int i, j,idx;
    char curr[formula[r][c].size()];
    ssheet[r][c] = 0;
    for(int k= 1, idx = 0; k <= formula[r][c].size(); ++k){
        if(s[k] == '+' || k == formula[r][c].size()){
            int p;
            j = 0;
            for(p = 0; p < formula[r][c].size() && !isdigit(curr[p]); ++p){
                j = j*26 + curr[p]-'A';
            }   
            for(; p < )    
            // i = stoi(curr.substr(p));
            // --i;
            // cout << i << ' ' << j << ' ' << p << ' ' << curr << endl;
            ssheet[r][c] += dfs(i,j);
            idx = 0;
            // curr = "";
        }
        else curr[idx++] = s[k];
        // else curr += s[k];
    }
    return ssheet[r][c];
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d %d", &m, &n);
        FOR(i,n) FOR(j, m) ssheet[i][j] = 0, formula[i][j].clear();
        FOR(i,n) FOR(j,m){
            cin >> s;
            if(s[0] == '=') formula[i][j] = s,ssheet[i][j] = INF;
            else ssheet[i][j] = stoi(s);
        }
        FOR(i,n) FOR(j,m) if(ssheet[i][j] == INF) ssheet[i][j] = dfs(i,j);
        FOR(i,n) { FOR(j,m) {if(j) cout << ' '; cout << ssheet[i][j];} cout << endl; }
    }
    
}