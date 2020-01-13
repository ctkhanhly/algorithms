#include <iostream>
#include <string>
using namespace std;

//seems to work, but TLE, 25*2^25???
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 25;
int T,n, dp[1<<N];
string s;
void printBit(int k,int i){
    if(i==n)  return;
    cout << (k%2);
    printBit(k/2, i+1);
}
bool canEmpty(int bm){
    if(dp[bm] != -1) return dp[bm];
    int mask = bm, idx = -1;
    char last = 'c';
    for(int j = 0; j < n; ++j){
        if(!(mask&(1<<j)) && last == s[j]) {
            mask |= (1<<idx);
            while(j < n && !(mask&(1<<j)) && s[j] == last){
                mask |= (1<<j);
                if(canEmpty(mask)) return dp[mask] =1 ;
                while(j<n && mask&(1<<j)) ++j;
            }
            --j, mask = bm, last = s[j], idx = j;
        }
        if(!(mask &(1<<j))) last = s[j], idx = j;
    }
    
    return dp[bm] = 0;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        cin >> s;
        n = s.size();
        FOR(j, 1<<n) dp[j] = -1;
        dp[(1<<n)-1] = 1;
        if(canEmpty(0)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}