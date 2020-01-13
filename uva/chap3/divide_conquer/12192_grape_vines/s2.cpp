#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 500;
int g[N][N], contour[N][N], n, m,Q,l,h,side, col,endRow, endCol;
int* lo;
bool found;

int main(){
    while(scanf("%d %d", &n, &m), n|| m){
        FOR(i,n) FOR(j,m) scanf("%d", &g[i][j]);
        scanf("%d", &Q);
        FOR(q,Q){
            scanf("%d %d", &l, &h);
            side = 0;
            FOR(row,n){
                lo = lower_bound(g[row], g[row]+m, l);
                col = (lo-g[row]);
                for(int sz = side; sz < n; ++sz){
                    endRow = row + sz;
                    endCol = col + sz;
                    if(endRow >= n || endCol >= m || g[endRow][endCol] > h) break;
                    side = max(side, sz+1);
                }
            }
            cout << side << endl;
        }
       printf("-\n");
    }
}