#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10000;
int prices[N],m,n,ans,l,r,mid,p1,p2,z,i,j;
int* p;
int main(){
    z = 0;
    while(scanf("%d", &n)==1){
        FOR(i,n) scanf("%d", &prices[i]);
        sort(prices, prices+n);
        scanf("%d", &m);
        i =  0, j = n-1;
        while(i < j){
            if(prices[i] + prices[j] > m) --j;
            else if(prices[i] +prices[j] < m) ++i;
            else p1 = prices[i], p2 = prices[j], ++i,--j;
        }
        // if(z) puts("");
        printf("Peter should buy books whose prices are %d and %d.\n\n", p1,p2);
        // ++z;
    }
}