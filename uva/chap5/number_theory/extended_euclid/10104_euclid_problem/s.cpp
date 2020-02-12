#include <iostream>
using namespace std;


//AC
typedef long long ll;
ll A, B,d,x,y;
void extendedEuclid(ll a, ll b){
    if(b == 0) { x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main(){
    while(scanf("%lld %lld", &A, &B)==2){
        extendedEuclid(A,B);
        printf("%lld %lld %lld\n", x,y,d);
    }
}