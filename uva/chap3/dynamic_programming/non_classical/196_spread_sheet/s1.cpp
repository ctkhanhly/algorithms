#include <iostream>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int INF = INT_MIN;
const int N = 1000;
const int M = 18278;
int T, m,n, ssheet[N+10][M+10];
string formula[N+10][M+10],s;


int dfs(int r, int c){
    if(ssheet[r][c] != INF) return ssheet[r][c];
    int i, j;
    string curr;
    ssheet[r][c] = 0;
    for(int k= 1; k <= formula[r][c].size(); ++k){
        if(formula[r][c][k] == '+' || k == formula[r][c].size()){
            int p;
            j = 0;
            for(p = 0; p < curr.size() && !isdigit(curr[p]); ++p){
                j = j*26 + curr[p]-'A'+1;//padded with 1 because 0 would never move up the ladder
            }       
            i = stoi(curr.substr(p));
            --i;
            --j;
            ssheet[r][c] += dfs(i,j);
            
            curr = "";
        }
        else curr += formula[r][c][k];
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
        FOR(i,n) FOR(j,m) if(ssheet[i][j] == INF) dfs(i,j);
        FOR(i,n) { FOR(j,m) {if(j) cout << ' '; cout << ssheet[i][j];} cout << endl; }
    }
    
}