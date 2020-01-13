#include <iostream>
#include <math.h>
using namespace std;
//AC 
//8!, O(n^2) each call
#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
const int N = 8;
int row[N],res,z;
bool place(int r, int c){
    for(int prev = 0; prev < c; ++prev){
        if(row[prev] == r || abs(row[prev] -r) == abs(prev -c)) return false;
    }
    return true;
}
int backtrack(int c){
    if(c == N) return 0;
    int ans = N+1;
    FOR(r, N){
        if(place(r,c)) {
            int a = row[c];
            if(row[c] == r) ans = min(ans, backtrack(c+1));
            else row[c] = r, ans = min(ans, 1+backtrack(c+1));
            row[c]=a;
        }
    }
    return ans;
}
int main(){
    z = 1;
    while(scanf("%d %d %d %d %d %d %d %d", &row[0], &row[1], &row[2], &row[3], &row[4], &row[5], &row[6], &row[7])==8){
        FOR(i,N) --row[i];
        res = backtrack(0);
        printf("Case %d: %d\n", z, res == N+1 ? 0 : res);
        ++z;
    }
}