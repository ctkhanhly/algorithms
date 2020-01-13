#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int T, n;
string S;
unordered_map<string,bool> dp;
bool search(const string& s){
    // cout  << s <<  endl;
    if(s.empty()) return 1;
    if(dp.count(s)) return dp[s];
    int left = 0, right = 0;
    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] == s[i+1]){
            left = i-1; 
            while(i+1< n && s[i] == s[i+1]) ++i;
            right = i;
            // cout << right << ' ' << s.size() << endl;
            if(search( s.substr(0,left+1) + s.substr(right+1)) ) return dp[s] = 1;
        }
    }
    return dp[s] = 0;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        cin >> S;
        n = S.size();
        cout << search(S) << endl;
    }
}