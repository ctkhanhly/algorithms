#include <iostream>
#include <algorithm>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 500;
int m,n, leftDiag[2*N-1][N], idx[2*N-1],side, lo,hi,Q;//go down at most N time
int* l, *u;
int main(){
    while(scanf("%d %d", &n,&m), m||n){
        FOR(i, m+n) idx[i] = 0;
        FOR(r,n) FOR(c,m) scanf("%d",&leftDiag[r-c+m-1][idx[r-c+m-1]++]);
        scanf("%d",&Q);
        FOR(q,Q){
            scanf("%d %d", &lo, &hi);
            side = 0;
            for(int i = m+n-1; i >= 0; --i){
                l = lower_bound(leftDiag[i], leftDiag[i] + idx[i], lo);
                u = upper_bound(l, leftDiag[i] + idx[i], hi);
                side = max(side, (int)(u-l));
            }
            cout << side << endl;
        }
        printf("-\n");
    }
}