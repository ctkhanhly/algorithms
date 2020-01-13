#include <iostream>
#include <vector>
using namespace std;

const int N = 200;
const int M = 10;
typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,Q,d,m, nums[N+5], dp[N+5][M], res;

int main(){
    scanf("%d", &T);
    while(scanf("%d %d", &n, &q), n || q){
        FOR(i,n) scanf("%d",nums[i]);
        //size and sum, 2^32*200
        FOR(q,Q){
            scanf("%d %d", &d, &m);
            res = 0;
            FOR(i, n) FOR(j, m) dp[i][j] =  0;
            FOR(i,n) FOR(j,m){
                
            }
        }
    }