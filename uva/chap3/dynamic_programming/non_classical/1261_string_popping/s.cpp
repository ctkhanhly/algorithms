#include <iostream>
#include <string>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 25;
int T,n, dp[N][1<<N];
string s;
void printBit(int k,int i){
    if(i==n)  return;
    cout << (k%2);
    printBit(k/2, i+1);
}
bool canEmpty(int i, int bm){
    if(bm == (1<<n)-1) return 1;
    // printBit(bm,0);
    // cout << endl;
    if(dp[i][bm] != -1) return dp[i][bm];
    // cout << i << ' ' << bm << endl;
    int mask = bm, idx = -1;
    char last = 'c';
    for(int j = i; j < n; ++j){
        
        if(!(mask&(1<<j)) && last == s[j]) {
            mask |= (1<<idx);
            while(j < n && !(mask&(1<<j)) && s[j] == last){
                mask |= (1<<j);
                if(canEmpty(j+1, mask)) { printBit(mask,0); return dp[i][mask] =1 ;}
                ++j;
            }
            // cout << idx << ' ' << j<< endl;
            // printBit(mask,0);
            // cout << endl;
            // if(canEmpty(mask)) return dp[mask] =1 ;
            
            if(j == n) return dp[i][bm] = 0;
            // cout << "here\n";
            --j, mask = bm, last = s[j], idx = j;
        }
        if(!(mask &(1<<j))) last = s[j], idx = j;
        // cout << last << ' ' << idx << endl;
         
    }
    last = 'c', mask = bm, idx = -1;
    FOR(j,i){
        if(!(mask&(1<<j)) && last == s[j]) {
            mask |= (1<<idx);
            while(j < n && !(mask&(1<<j)) && s[j] == last){
                mask |= (1<<j);
                if(canEmpty(j+1, mask)) { printBit(mask,0); return dp[i][mask] =1 ;}
                ++j;
            }
            // cout << idx << ' ' << j<< endl;
            // printBit(mask,0);
            // cout << endl;
            // if(canEmpty(mask)) return dp[mask] =1 ;
            
            if(j == n) return dp[i][bm] = 0;
            // cout << "here\n";
            --j, mask = bm, last = s[j], idx = j;
        }
        if(!(mask &(1<<j))) last = s[j], idx = j;
    }
    return dp[i][bm] = 0;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        cin >> s;
        n = s.size();
        FOR(i,n) FOR(j, 1<<n) dp[i][j] = -1;
        // dp[(1<<n)-1] = 1;
        if(canEmpty(0,0)) cout << 1 << endl;
        else cout << 0 << endl;
        // cout << endl;
    }
}