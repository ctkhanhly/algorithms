#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

//AC

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
const int M = 18278;
const int N = 1000;
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int incom[N+10][M+10];
int ssheet[N+10][M+10],T,n,m,num,sz,idx,lastSz, r,c;
vector<ii> prec[N+10][M+10];
string s,curr;
vector<string> perms;
unordered_map<string, int> transformer;
int main(){
    transformer.clear(), perms.clear();
    idx = 0;
    FOR(i, 26) perms.pb(string(1,ALP[i])),transformer[perms.back()] = idx++;
    lastSz = 0;
    for(int size = 2; size <= 3; ++size){
        sz = perms.size();
        for(int j = lastSz; j < sz; ++j){
            FOR(i, 26){
                perms.pb(perms[j] + ALP[i]);
                transformer[perms.back()] = idx++;
            }
        }
        lastSz = sz;
    }

    scanf("%d", &T);
    FOR(z,T){
        scanf("%d %d", &m, &n);
        
        FOR(i,n) FOR(j,m) prec[i][j].clear(), incom[i][j] = ssheet[i][j] = 0;
        FOR(i, n){
            FOR(j, m) {
                cin >> s;
                if(s[0] == '='){
                    curr.clear();
                    
                    for(int k = 1; k <= s.size(); ++k){
                        if(s[k] == '+' || k == s.size()) {
                            r = stoi(curr);
                            --r;
                            if(r <=i && c <=j && incom[r][c] == 0) ssheet[i][j] += ssheet[r][c];
                            else{
                                prec[r][c].pb({i,j});
                                ++incom[i][j];
                            }
                            curr = "";
                        }
                        else if(isdigit(s[k]) && !isdigit(s[k-1])){
                            c = transformer[curr];
                            curr = "", curr += s[k];
                        }
                        else curr += s[k];
                    }
                }
                else {
                    num = stoi(s);
                    ssheet[i][j] = num;
                }
            }
        }

        queue<ii> q; 
        FOR(i,n) FOR(j,m) if(incom[i][j]== 0 && !prec[i][j].empty()) q.push({i,j});
        ii pa;
        int i,j;
        while(!q.empty()){
            pa = q.front();
            q.pop();
            r = pa.fi, c = pa.se;
            FOR(k, prec[r][c].size()){
                i = prec[r][c][k].fi, j = prec[r][c][k].se;
                ssheet[ i ][ j ] += ssheet[r][c];
                if(--incom[ i ][ j ] == 0){
                    q.push({ i , j });
                }
            }
        }
        FOR(i,n) { FOR(j,m) {if(j) cout << ' '; cout << ssheet[i][j];} cout << endl; }
    }
}