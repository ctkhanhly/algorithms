#include <iostream>
#include <vector>
using namespace std;

const int N = 200;
const int M = 10;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,Q,d,m, nums[N+5], dp[1<<M], res;
vi subsets;
int LSOne(ink) {return k&(-k);}
int countBm(int bm){
    int ans = 0;
    FOR(int i = bm; i > 0; i-= LSOne(i)) ++ans;
    return ans;
}
int backtrack(int bm, int sum){
    if(countBm(bm) == m) return sum %d == 0; 
    int ans = 0;
    FOR(i, n){
        if(!(bm&(1<<i))) 
            ans += backtrack(bm | (1<<i), sum + nums[i]);
    }
    return ans;
}
//10^16
void generateSubsets(int sz, int bm, int i){
    if(countBm(bm) == m) {
        subsets.pb(vi());
    }
    else{
        int ans = 0;
        for(int j = i; j <= n-(m-sz); ++j){
            if(!(bm & (1<<j))) {
                subsets.back().pb(nums[j]);
                generateSubsets(sz+1, bm | (1<<j), j+1);
            }
        }
    }
        
    
}
int main(){
    subsets.clear();
    //generateSubsets
    while(scanf("%d %d", &n, &q), n || q){
        FOR(i,n) scanf("%d",nums[i]);
        //size and sum, 2^32*200
        FOR(q,Q){
            scanf("%d %d", &d, &m);
            res = 0;
            
        }
    }
}