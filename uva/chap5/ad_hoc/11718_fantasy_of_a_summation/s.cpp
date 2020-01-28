#include <iostream>
using namespace std;

//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int T, n,m, num;
ll sum, k;

ll pow(ll n1, ll k1){
    if(k1 == 0) return 1;
    ll sqt = (pow(n1,k1/2)%m);
    return (((sqt*sqt)%m) * ((k1 &1 ? n1 : 1) %m)) % m;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d %lld %d", &n, &k, &m);
        sum = 0;
        FOR(i,n) scanf("%d", &num), sum = ((sum %m) + (num%m)) %m;
        //n^k*k values are distributed evenly to each number in the array
        sum = ((sum%m) *((pow(n,k-1)%m)*(k%m))%m) %m;
        printf("Case %d: %lld\n", z+1, sum);
    }
}