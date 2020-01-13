#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;


//AC by converting x,r from int to double woohooo lolzz
typedef pair<double,double> dd;
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second
const int N = 10000;
int n,l,w,ans;
double dx,ri,le, lr,x,r;
int main(){
    while(scanf("%d %d %d", &n, &l, &w)==3){
        set<dd> spr;
        FOR(z,n) {
            scanf("%lf %lf", &x, &r), dx = sqrt(max(r*r-w*w/4.0,0.0));
            if(dx){
                le = max(0.0, x-dx), ri = x+dx;
                spr.insert( {le, ri});
            }
        }
        ans = lr = 0;
        while(!spr.empty()){
            ri = lr; 
            //all reachable next sprinklers
            while(!spr.empty() && spr.begin()->fi <= lr){
                ri = max(ri, spr.begin()->se);
                spr.erase(spr.begin());
            }
            ++ans;
            if(ri >= l) { lr = ri; break;}
            if(ri == lr) break;
            lr = ri;
        }
        if(lr >= l && ans) cout << ans << endl;
        else cout << -1 << endl;
    }
}

/*

1. Min > 0
2. Max < l
3. There's a gap

*/