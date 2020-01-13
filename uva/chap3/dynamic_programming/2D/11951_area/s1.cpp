#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
int T, n, m, K, idx[2*N+5],r1,c1,r2,c2;
ll g[N+5][N+5], leftDiag[2*N+5][n+5];
ll* lo;
map<int, ll> areas;
int calculateRow(int i, int idxi){
    if(i <= m) return idxi;
    return i-m+1+idxi;
}
int calculateCol(int i, int idxi){
    if(i <= m) return m-1-i+idxi;
    return idxi;
}
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d %d %d", &n, &m, &K);
        FOR(i, m+n) idx[i] = 0;
        FOR(i, n) { FOR(j, m) {
            scanf("%d", &g[i][j]);
            if(i) g[i][j] += g[i-1][j];
            if(j) g[i][j] += g[i][j-1];
            if(i && j) g[i][j] -= g[i-1][j-1];
            cout << g[i][j] << ' ';
            leftDiag[i-j+m-1][idx[i-j+m-1]++] = g[i][j];
        }
        cout << endl;}
        areas.clear();
        FOR(i, m+n){
            FOR(j, idx[j]){
                lo = lower_bound(leftDiag[i], leftDiag[i]+idx[i], leftDiag[i][j]-K);
                r1 = calculateRow(i, lo-leftDiag[i]);
                c1 = calculateCol(i, lo-leftDiag[i]);
                r2 = calculateRow(i, j);
                c2 = calculateCol(i, j);
                S = (r2-r1+1)*(c2-c1+1);
                // P = leftDiag
                if(!areas.count(S) || (areas.count(S) && areas[S] < ))
            }
            
        }
    }
}