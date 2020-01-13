#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int T, N, LIS, LDS;
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d", &N);
        // cout << N << endl;
        int heights[N], widths[N], lis[N], lds[N];
        FOR(i,N) scanf("%d", &heights[i]);
        FOR(i,N) scanf("%d", &widths[i]), lis[i] = lds[i] = widths[i];
        LIS = LDS = 0;
        FOR(i, N){
            FOR(j, i) {//h[i] > h[j]
                if(heights[i] > heights[j] && lis[j] + widths[i] > lis[i]) {
                    lis[i] =lis[j] + widths[i];
                }
                if(heights[i] < heights[j] && lds[j] + widths[i] > lds[i]) {
                    lds[i] =lds[j] + widths[i];
                }   
            }
            LIS = max(LIS, lis[i]);
            LDS = max(LDS, lds[i]);
        }
        printf("Case %d. ", t+1);
        if(LIS >= LDS) printf("Increasing (%d). Decreasing (%d).\n",LIS, LDS);
        else printf("Decreasing (%d). Increasing (%d).\n",LDS, LIS);
    }
}