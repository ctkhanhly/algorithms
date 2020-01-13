#include <iostream>
#include <algorithm>
using namespace std;


//dont even look....
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10000;
int prices[N],m,n,ans,l,r,mid,p1,p2,z;
int main(){
    z = 0;
    while(scanf("%d", &n)==1){
        FOR(i,n) scanf("%d", &prices[i]);
        sort(prices, prices+n);
        scanf("%d", &m);
        // FOR(i,n) cout << prices[i] << ' ';
        // cout << endl;
        // while(p1 < p2){
        //     if(prices[p1] + prices[p2] > m) --p2;
        //     else if(prices[p1] + prices[p2] < m) ++p1;
        // }
        ans = 0;
        FOR(i,n){
            l = 0, r = n;
            // cout << "price " << prices[i] << endl;
            while(r > l){
                mid = (l+r)/2;
                // cout << l << ' ' << mid << ' ' << r << endl;
                if(mid+1 < n && (prices[i] + prices[mid+1]) > m) r = mid;
                else l = mid+1;
            }
            //0-1, 0-2
            // cout << "fin bin " << l << endl;
            // if(l == n && prices[l-1] + prices[i] <=m)--l;
            // cout << l << endl;
            // --l;
            if(l==i || l == n || prices[l]+ prices[i] > m) {
                if(l == 0) break; 
                else --l;
            }  
            // cout << "here\n";
            if(i != l && prices[i] + prices[l] <=m && prices[i] + prices[l] > ans) {
                ans = prices[i] + prices[l], p1 = min(prices[i], prices[l]), p2 = max(prices[i], prices[l]);
                // cout << i << ' ' << l << ' ' << prices[i] << ' ' << prices[l] << endl;
            }
            
                
            
        }
        if(z) puts("");
        printf("Peter should buy books whose prices are %d and %d.\n", p1,p2);
        ++z;
    }
}