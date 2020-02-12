#include <iostream>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n, SPF[1000000], primes[1000000],idx;
void sieve(){
    FOR(i, n+1) SPF[i] = 0;
    idx = 0;
    for(int i = 2; i < 1000000; ++i){
        if(SPF[i] == 0){
            primes[idx++] = i;
            SPF[i] = i;
        }
        for(int j = 0; j < idx && primes[j] <= SPF[i] && i*primes[j] < 1000000; ++j){
            SPF[i*primes[j]] = primes[j];
        }
    }
}
int main(){
    sieve();
    while(scanf("%d", &n),n){
        // cout << idx << endl;
        FOR(i,idx) {
            // if(primes[i] >= n) break;
            // cout << primes[i] << ' ' << n-primes[i] << endl;
            // cout << n-primes[i] << ' ' << SPF[n-primes[i]] << endl;
            if(SPF[n-primes[i]] == n-primes[i]){
                printf("%d = %d + %d\n", n, primes[i], n-primes[i]);
                break;
            }
        }
    }
}