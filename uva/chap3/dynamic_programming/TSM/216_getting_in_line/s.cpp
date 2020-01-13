#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 8;
const int INF = 8*150*2+100;
int x[N], y[N], n,z, xc, yc,p[N], currP[N], finalP[N],s;
double dist[N][N],dp[N][1<<N],ans, startAns;
int tsp(int i, int bm){
    if(bm == (1<<n) -1)  return 0;
    if(dp[i][bm] != -1) return dp[i][bm];
    int res = INF;
    for(int j = 0; j < n; ++j){
        if(!(bm& (1<<j))) {
            int curr = dist[i][j] + tsp(j, bm | (1<<j));
            if(curr < res){
                p[i] = j;
                // if(p[j] ==i ) p[j] = -1;
                res = curr;
            }
            // res = min(res, dist[i][j] + tsp(j, bm | (1<<j)));
        }
    }
    return dp[i][bm] = res;
}
int main(){
    z = 1;
    while(scanf("%d", &n), n){
        // FOR(i,n) FOR(j,n)
        FOR(i,n) {
            scanf("%d %d", &x[i], &y[i]);
            dist[i][i] = 0;
            finalP[i] = p[i] = -1;
            FOR(j,i){
                xc = x[i]-x[j], yc =y[i]-y[j];
                dist[j][i] = dist[i][j] = sqrt(xc * xc + yc*yc);
                // cout << i << ' ' << j << ' ' << ' ' << xc << ' ' << yc << ' ' << dist[i][j] << endl;
            }
        }
        ans = INF;
        FOR(i,n){
            FOR(j,n) { p[j] = -1; FOR(k, 1 <<n) dp[j][k] = -1;}
            startAns = tsp(i, 1<<i);
            // cout << startAns << endl;
            if(startAns < ans){
                copy(p, p+n, finalP);
                s = i;
                ans = startAns;
                // cout << ans << endl;
            }
        }
        cout << s << endl;
        FOR(i,n) cout << finalP[i] << ' ';
        cout << endl;
        printf("**********************************************************\n");
        printf("Network #%d\n",z);
        FOR(i, n-1) {
            printf("Cable required to connect (%d,%d) to (%d,%d) is  %.2lf feet.\n", 
                x[s], y[s], x[ finalP[s] ], y[ finalP[s] ], dist[s][ finalP[s] ]+16);
            s = finalP[s];
        }
        printf("Number of feet of cable required is %.2lf.\n", ans+16*(n-1));
        ++z;
    }
}