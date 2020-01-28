#include <iostream>
#include <math.h>
using namespace std;

//AC
typedef long long ll;
ll n, x;
int main(){
    while(scanf("%lld",&n) == 1){
        if(n%3 || n <= 0) cout << 0 << endl;
        else{
            // x= sqrt(n/3);
            // if(x*x == n/3) cout << 1 << endl;
            // else cout << 0 << endl;
            cout << 1 << endl;
        }
        
    }
}