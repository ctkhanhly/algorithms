#include <iostream>
#include <algorithm>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10000;
int prices[N],m,n,ans,l,r,mid,p1,p2,z;
int* p;
int main(){
    z = 0;
    while(scanf("%d", &n)==1){
        FOR(i,n) scanf("%d", &prices[i]);
        sort(prices, prices+n);
        scanf("%d", &m);
        ans = 0;
        p1 = prices[0], p2 = prices[n-1];
        FOR(i,n){
            if(m < 2*prices[i]) break;//upper half
            p = find(prices+i+1, prices+n, m-prices[i]);
            // cout << *p << ' ' << prices[i] << endl;
            
            if(p != prices+n && *p-prices[i] < p2-p1){
                p1= prices[i], p2 = *p;
            }
        }
        // if(z) puts("");
        printf("Peter should buy books whose prices are %d and %d.\n\n", p1,p2);
        // ++z;
    }
}