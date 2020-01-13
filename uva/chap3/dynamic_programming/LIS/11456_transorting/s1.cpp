#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


typedef vector<int> vi;
#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
#define pb push_back
const int N = 2000;//ok 10^6
int t,n,res;
int arr[N];
int dp[N];
vi lis;
void LIS(){
    for(int i = 0; i < n; ++i){
        if(arr[i] > lis.back()) lis.pb(arr[i]);
        *lower_bound(arr, arr+n, arr[i]) = arr[i];
    }
    res = lis.size();
}
int main(){
    cin >> t;
    FOR(z,t){
        lis.clear();
        cin >> n;
        FOR(i,n) dp[i] = 0;
        if(n) dp[0] = 1;
        FOR(q, n) cin >> arr[q];
        res = 0;
        LIS();
        cout << res << endl;
    }
}