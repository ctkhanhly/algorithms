#include <iostream>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int num, SPF[400], primes[400], fact[400], PF, cnt,idx, mxP, ans[720];
void sieve(){
    FOR(i,367) SPF[i] = 0;
    idx = 0;
    for(int i = 2; i <= 366; ++i){
        if(SPF[i] == 0 ){
            primes[idx++] = i;
            SPF[i] = i;
        }
        for(int j = 0; j < idx && primes[j] <= SPF[i] && primes[j]*i <= 366; ++j){
            SPF[primes[j]*i] = primes[j];
        }
    }
}
void acquireFactors(int n){
    cnt = idx = 0;
    PF = primes[idx];
    while(PF * PF < n){
        while(n%PF == 0){ n/= PF, cnt++;}
        fact[idx] = cnt;
        cnt = 0;
        PF = primes[++idx];
    }
    if(n!= 1) fact[idx++] = 1;
    mxP = max(mxP, idx);
}
int main(){
    sieve();
    while(scanf("%d", &n), num){
        mxP = 0;
        FOR(i, n+1) fact[i] = 0;
        for(int i = 1; i <= num; ++i) 
            acquireFactors(i);
        while(fact[mxP]){

        }
    }
}