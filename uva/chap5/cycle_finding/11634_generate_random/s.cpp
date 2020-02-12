#include <iostream>
#include <unordered_set>
using namespace std;

//AC
typedef long long ll;
ll a,p;
int steps = 0;
unordered_set<ll> seq;
int main(){
    while(scanf("%lld", &a), a){
        p = a;
        steps = 1;
        seq.clear();
        while(!seq.count(p)){
            seq.insert(p);
            p = (p*p/100)%10000;
            ++steps;
        }
        cout  << --steps << endl;
    }
}