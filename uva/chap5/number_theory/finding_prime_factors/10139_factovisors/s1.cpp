#include <iostream>
#include <unordered_map>
#include <set>
#include <limits.h>
using namespace std;
 
 //AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second
const int MX = 1e7;
int n,m, SPF[MX], primes[MX], idx, PF, PFN, cntn, cntm,m1;
bool hasAns;
void sieve(){
    FOR(i, MX) SPF[i] = 0;
    idx = 0;
    for(int i = 2; i < MX; ++i){
        if(SPF[i] == 0){
            primes[idx++] = i;
            SPF[i] = i;
        }
        for(int j = 0; j < idx && primes[j] <= SPF[i] && primes[j]*i < MX; ++j){
            SPF[primes[j]*i] = primes[j];
        }
    }
}
bool solve(){
    PF = primes[0];
    for(int i = 0; i < idx && PF*PF <=m; ++i){
        PF = primes[i];
        if(m%PF == 0){
            cntn = cntm = 0;
            while(m%PF == 0) ++cntm, m/=PF;
            PFN = PF;
            while(PFN <= n){
                cntn += n/PFN;//periods of PFN
                PFN*=PF;
            }
            if(cntn < cntm || n < PF) return 0;
        }
    }
    return m != 1 ? n >= m : 1;
}
int main(){
    sieve();
    while(scanf("%d %d", &n, &m)==2){
        m1 = m;
        if(solve()) printf("%d divides %d!\n", m1, n);
        else printf("%d does not divide %d!\n", m1, n);
    }
}
//https://primes.utm.edu/nthprime/index.php#nth