#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int t,m,n;
char c;
int main(){
    cin >> t;
    FOR(z, t){
        cin >> c >> m >> n;
        // cout << c << ' ' << m << ' ' << n << endl;
        if(c == 'r') cout << min(m,n) << endl;
        else if(c == 'Q') cout << min(m,n) << endl;
        else if(c == 'K') {
            cout << ((m+1)/2)*((n+1)/2) << endl;
        }
        else{
            if(m > n) swap(m,n);
            cout << ((m+1)/2)*((n+1)/2) + (n/2)*(m/2) << endl;
        }
    }
}