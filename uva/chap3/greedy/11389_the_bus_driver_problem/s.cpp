#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
int n,d,r, morning[N], afternoon[N],ans;
int main(){
    while(scanf("%d %d %d", &n, &d, &r), n || d || r){
        FOR(z,n) scanf("%d", &morning[z]);
        FOR(z,n) scanf("%d", &afternoon[z]);
        sort(morning, morning+n);
        sort(afternoon, afternoon+n, greater<int>());
        ans = 0;
        FOR(i,n) if(afternoon[i]+morning[i] > d) ans += afternoon[i]+morning[i]-d;
        cout << ans *r << endl;
    }
}