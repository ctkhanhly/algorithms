#include <iostream>
using namespace std;
 

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 1e5;
int n, ladder[N+1],T, lo, hi, mid;
bool check(int k){
    FOR(i, n) {
        if(ladder[i+1]-ladder[i] > k) return false;
        else if(ladder[i+1] - ladder[i] == k) --k;
    }
    return true;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d", &n);
        ladder[0] = 0;
        FOR(p, n) scanf("%d", &ladder[p+1]);
        lo = 1, hi = 1e7;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid+1;
        }
        printf("Case %d: %d\n", z+1, lo);
    }
}