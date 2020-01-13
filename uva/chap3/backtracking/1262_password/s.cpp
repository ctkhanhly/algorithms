#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
const int R = 5;
const int C = 6;
string s,res;
int T, K,k;
char g1[R][C], g2[R][C];
bool found;
void search(int r, int c1, int c2){
    if(found) return;
    int i = c1,j=c2;
    // cout << r << ' ' << c1 << ' ' << c2 << endl;
    while(i < C && j < C){
        if(i && g1[r][i] == g1[r][i-1] || g1[r][i] < g2[r][j]) ++i;
        else if(j && g2[r][j] == g2[r][j-1] || g1[r][i] > g2[r][j]) ++j;
        else {//if=(g1[r][i] == g2[r][j]) 
            s.pb(g1[r][i]);
            if(r == R-1) {
                ++k;
                if(k== K) { found = true; res = s; return; }
            }
            else search(r+1, 0,0);
            s.pop_back();
            ++i,++j;
        }
        // else if(g1[r][i] < g2[r][j]) ++i;
        // else ++j;
    }
}
int main(){
    cin >> T;
    FOR(z,T){
        // cout << z << endl;
        cin >> K;
        FOR(i, C) {
            cin >> s;
            // cout << s << endl;
            FOR(j, R) g1[j][i] = s[j];
        }
        // cout << endl;
        FOR(i, C) {
            cin >> s;
            FOR(j, R) g2[j][i] = s[j];
        }
        FOR(i,R) sort(g1[i], g1[i] + C), sort(g2[i], g2[i] + C);
        // FOR(i, R) {FOR(j, C) cout << g1[i][j]; cout << endl;}
        // cout << endl;
        // FOR(i, R) {FOR(j, C) cout << g2[i][j]; cout << endl;}
        k = 0;
        found = false;
        s.clear();
        res.clear();
        search(0,0,0);
        if(found) cout << res << endl;
        else cout << "NO" << endl;
    }
    
}