#include <iostream>
#include <math.h>
#include <string>
using namespace std;


//AC
typedef pair<int,int> ii;
#define  FOR(i,n) for(int  i = 0;  i < (int)n; ++i)
#define fi first
#define se second
int n, a, e,j,num, PF, SPF[32770], primes[100000],idx;
ii fact[10000];
string s;
void sieve(){
    // cout << "in sieve\n";
    FOR(i, 32770) SPF[i] = 0;
    idx = 0;
    for(int i = 2; i <= 32767; ++i){
        if(SPF[i] == 0){
            primes[idx++] = i;
            SPF[i] = i;
        }
        for(int k = 0; k < idx && primes[k] <= SPF[i] && primes[k]*i <= 32767; ++k){
            SPF[primes[k]*i] = primes[k];
            // cout << primes[k]*i << endl;
        }
    }
    // cout << "exitting sieve\n";
}
void acquireFactors(){
    idx = 0;
    PF = SPF[n];
    while(n > 1){
        fact[idx].se = 0;
        fact[idx].fi = PF;
        while(n%PF == 0) ++fact[idx].se, n/= PF;
        PF = SPF[n];
        ++idx;
    }
    // if(n!= 0) fact[idx++] = 1;
}
int main(){
    sieve();
    while(getline(cin,s)){
        // cout << s << endl;
        if(s.size() == 1 && s[0]=='0') break;
        n  =  1,num = 0;
        
        FOR(i, s.size()){
            if(isdigit(s[i])){
                j = i;
                while(i < s.size() && isdigit(s[i])) ++i;
                ++num;
                if(num&1) a = stoi(s.substr(j,i-j));
                else e= stoi(s.substr(j,i-j)), n*= pow(a,e);//, cout << a << ' ' << e << endl;
                // cout << num << endl;
            }
        }
        // cout <<  n << endl;
        // FOR(i,min(n,10000)) fact[i] = 0;
        --n;
        acquireFactors();
        // cout <<  idx << endl;
        for(int i = idx-1; i >= 0; --i){
            if(i<idx-1) printf(" ");
            printf("%d %d", fact[i].fi, fact[i].se);
        }
        puts("");
    }
}