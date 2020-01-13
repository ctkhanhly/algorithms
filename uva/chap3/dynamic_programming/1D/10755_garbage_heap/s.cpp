#include <iostream>
#include <limits.h>
using namespace std;


//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 20;
int T,A,B,C;
ll mx, currSum, elem, g[N+5][N+5][N+5];
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d %d %d", &A, &B, &C);
        // cout << A << ' ' << B << ' ' << C << endl;
        FOR(x, A) FOR(y, B) FOR(z,C){
            scanf("%lld", &g[x][y][z]);
            if(x) g[x][y][z] += g[x-1][y][z];//upper
            if(y) g[x][y][z] += g[x][y-1][z];//left
            if(x && y) g[x][y][z] -= g[x-1][y-1][z];
            // cout << g[x][y][z] << ' ';
        }
        
        mx = LLONG_MIN;
        FOR(sr, A)FOR(sc, B) for(int er = sr; er < A; ++er) for(int ec = sc; ec < B; ++ec) {
            currSum = 0;
            // cout << sr << ' ' << sc << ' ' << er << ' ' << ec << endl;
            FOR(z, C){
                elem = g[er][ec][z];
                // cout << elem << ' ';
                if(sr) elem -= g[sr-1][ec][z];
                if(sc) elem -= g[er][sc-1][z];
                if(sr && sc) elem += g[sr-1][sc-1][z];
                //Kardane
                
                currSum = max(currSum + elem, elem);
                // cout << elem << ' ' << currSum << endl;
                mx = max(mx, currSum);
            }
            // cout << endl;
        }
        if(t) puts("");
        printf("%lld\n", mx);
    }
}