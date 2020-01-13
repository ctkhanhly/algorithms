#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define eb emplace_back
int T,N,idx,widLIS,widLDS,pos,last;
vi::iterator lo;
vi::reverse_iterator hi;
vi lis, lds;
int calculateWidth(int i, int* p, int* width){
    if(i==-1) return 0;
    else return width[i] + calculateWidth(p[i],p, width);
}
int main(){
    scanf("%d", &T);
    FOR(t, T){
        scanf("%d", &N);
        int heights[N], widths[N], p[N],idx[N], wid[N];
        FOR(i,N) scanf("%d", &heights[i]);
        FOR(i,N) scanf("%d", &widths[i]);

        lis.clear(), lds.clear();
        widLIS = widLDS = 0;

        FOR(i,N) wid[i] = 0;
        //lis
        FOR(i,N){
            if(lis.empty() || heights[i] > lis.back()){
                pos = lis.size();
                lis.eb(heights[i]);
            }
            else{
                lo = lower_bound(lis.begin(), lis.end(), heights[i]);
                pos = lo - lis.begin();
                lis[pos] = heights[i];
            }
            
            // if(pos == lds.size() -1) last = i;
            
            // wid[pos] = max(wid[pos], widths[i] + (pos ? wid[pos-1] : 0)) ;
            // wid[i] = max(wid[i], widths[i] + (pos ? wid[ idx[pos-1] ] : 0)) ;

            //only goes back to the last match, not all possible previous matches
        //    wid[i] = max(wid[i], widths[i] + (p[i] != -1 ? wid[ p[i] ] : 0)) ;
        //linear update does not work: current sum vs later sum but pos-1 is not updated
        //as a possible path
            if(p[i] == -1 || widths[i] + wid[ p[i] ] > wid[i]){
                idx[pos] = i;
                p[i] = pos ? idx[pos-1] : -1;
                wid[i] = widths[i] + wid[ p[i] ];
                widLIS = max(widLIS, wid[i]);
            }
            
            // if(pos == lis.size() -1) {
            //     last = i;
                
            // }
        }
        // widLIS = wid[lis.size()-1];

        FOR(i,N) wid[i] = 0;
        //lds
        FOR(i,N){
            if(lds.empty() || heights[i] < lds.back()){
                pos = lds.size();
                lds.eb(heights[i]);
            }
            else{
                hi = upper_bound(lds.rbegin(), lds.rend(), heights[i]);
                pos = lds.size()-(hi - lds.rbegin());
                lds[pos] = heights[i];
                
            }
            // idx[pos] = i;
            
            // p[i] = pos ? idx[pos-1] : -1;
            // wid[i] = max(wid[i], widths[i] + (p[i] != -1 ? wid[ p[i] ] : 0)) ;
            // widLDS = max(widLDS, wid[i]);
            // if(pos == lds.size() -1) {
            //     last = i;
                
            // }
            if(p[i] == -1 || widths[i] + (p[i] != -1 ? wid[ p[i] ] : 0) > wid[i]){
                idx[pos] = i;
                p[i] = pos ? idx[pos-1] : -1;
                wid[i] = widths[i] + wid[ p[i] ];
                widLDS = max(widLDS, wid[i]);
            }
        }

        printf("Case %d. ", t+1);
        if(widLIS >= widLDS) printf("Increasing (%d). Decreasing (%d).\n",widLIS, widLDS);
        else printf("Decreasing (%d). Increasing (%d).\n",widLDS, widLIS);
    }
}