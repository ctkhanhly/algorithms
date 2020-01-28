#include <iostream>
#include <math.h>
using namespace std;


//AC
typedef unsigned int ui;
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
ll n,n1;
int ans;
bool works(ll num){
    n1 = n;
    FOR(i,num){
        if(n1 % num != 1) return false;
        n1 = (num-1)*(n1-1)/num;
    }
   return n1%num == 0;
}
int main(){
    //10^10 is exceeded => num < 10
    while(scanf("%lld", &n), n >= 0){
        ans = -1;
        for(int i = sqrt(n)+1; i > 0; --i){
            if(n%i == 1){
                if(works(i)) {ans = max(ans, i); break;}
            }
        }
        if(ans == -1) printf("%lld coconuts, no solution\n", n);
        else printf("%lld coconuts, %d people and 1 monkey\n",n, ans);
    }
}