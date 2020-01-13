#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


//AC
typedef pair<double,double> dd;
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second
const int N = 10000;
int n,l,w,ans,m;
dd sprinklers[N];
double dx,ri,x,r,lr;
int main(){
    while(scanf("%d %d %d", &n, &l, &w)==3){
        m =0;
        FOR(z,n) {
            scanf("%lf %lf", &x, &r),dx = sqrt(max(r*r-w*w/4.0,0.0)); 
            if(dx){
                sprinklers[m].fi = max(0.0,x-dx), sprinklers[m++].se = x + dx;
            }
        }
        sort(sprinklers, sprinklers+m);
        ans = lr = 0;
        FOR(i,m){
            ri = lr;
            while(i<m && sprinklers[i].fi <= lr){
                ri = max(ri, sprinklers[i++].se);
            }
            ++ans;
            if(ri >= l){ lr = ri; break;}
            if(ri == lr) break;
            lr = ri;
            --i;
        }
        if(lr >= l) cout << ans << endl;
        else cout << -1 << endl;
    }
}

/*

1. Min > 0
2. Max < l
3. There's a gap

*/