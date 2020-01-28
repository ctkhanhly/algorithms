#include <iostream>
#include <string>
// #include <math.h>
#include <sstream>
#include <vector>
using namespace std;


//AC
typedef long long ll;
typedef vector<ll> vll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
const int N = 2*1e9;
string s;
ll res,n,x,num;
vll arr;
bool isNeg;
ll pow(ll a, ll e){
    if(e == 0) return 1;
    ll sqt = pow(a, e/2);
    return sqt*sqt*(e&1? a : 1);
}
int main(){
    while(cin >> x){
        cin.ignore();
        getline(cin,s);
        res = 0;
        stringstream ss(s);
        arr.clear();
        while(ss >> num) arr.pb(num);
        FOR(i,arr.size()-1){
            n = (int)arr.size()-1-i;
            // if(n== 0) continue;
            res += arr[i] *n*pow(x,n-1);
        }
        cout << res << endl;
    }
}