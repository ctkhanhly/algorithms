#include <iostream>
#include <algorithm>
using namespace std;


//terrible
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 500;
int g[N][N], contour[N][N], n, m,Q,l,h,side, le, ri, mid, low, high,r,c1,c2,c;
int* lo, *hi;
bool found;

int main(){
    while(scanf("%d %d", &n, &m), n|| m){
        FOR(i,n) FOR(j,m) scanf("%d", &g[i][j]);
        scanf("%d", &Q);
        FOR(q,Q){
            scanf("%d %d", &l, &h);
            side = 0;
            FOR(i,n){
                lo = lower_bound(g[i], g[i]+m, l);
                hi = upper_bound(g[i], g[i]+m, h);
                c1 = (lo-g[i]);
                c = hi-g[i];
                for(int c2 = c-1; c2 >=c1+side; --c2){
                    le = i, ri = n;
                    while(le < ri){
                        mid = (le+ri)/2;
                        if(h >= g[mid][c2]) le = mid+1;
                        else ri = mid;//<h
                    }
                    r = le;
                    side = max(side, min(c2-c1+1, r-i));
                }
                
            }
            cout << side << endl;
        }
       printf("-\n");
    }
}
