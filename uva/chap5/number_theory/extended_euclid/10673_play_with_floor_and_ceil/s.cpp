#include <iostream>
#include <math.h>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
int T;
ll x,y,n,k,d;
void extendedEuclid(ll a, ll b){
    if(b == 0){ x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%lld %lld", &n, &k);
        extendedEuclid(n/k, ceil((double)n/k));
        printf("%lld %lld\n", x*(n/d),y*(n/d));
    }
}