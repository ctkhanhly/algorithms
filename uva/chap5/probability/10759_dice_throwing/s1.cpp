#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef long long ll;
int n, x;
ll num,dem, com, coin[155], coin2[155];
ll gcd(ll a, ll b){ 
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    while(scanf("%d %d", &n, &x), n+x){
        FOR(i, x) coin[i] = coin2[i] = 0;
        coin[0] = 1;
        for(int k = 0; k < n; ++k){
            for(int i = 1; i <= 6; ++i){
                for(int j = x-1; j >= i; --j){
                    coin2[j] += coin[j-i];
                    // cout << coin2[i] << endl;
                }
            }
            copy(coin2, coin2+x, coin);
            FOR(i, x) coin2[i] = 0;
        }
        num = 0;
        FOR(i, x) num += coin[i];
        // cout << num << endl;
        dem = pow(6,n);
        num = dem - num;
        // cout << num << ' '<< dem << endl;
        com = gcd(dem,num);
        dem /= com, num /= com;
        if(num == 0) printf("0\n");
        else if(dem == 1) printf("%lld\n", num);
        else printf("%lld/%lld\n", num,dem);
    }
}