#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

typedef pair<int,int> ii;
typedef pair<double,double> dd;
#define FOR(i,n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second
const int N = 10000;
int n,l,w,x,r,ans;
double dx,ri,le, lr;
bool noAns;
int main(){
    while(scanf("%d %d %d", &n, &l, &w)==3){
        set<dd> spr;
        FOR(z,n) {
            scanf("%d %d", &x, &r), dx = sqrt(max(r*r-w*w/4.0,0.0)), le = max(0.0, x-dx), ri = -x-dx;
            if(le!=-ri)spr.insert({le, ri});
        }
        noAns = spr.begin()->fi > 0;
        ans = lr = 0;
        // for(auto it = spr.begin(); it != spr.end(); ++it){
        //     cout << it->fi << ' ' << it->se << ',';
        // }
        // cout << endl;
        while(!spr.empty()){
            if(noAns) break;
            //wrong with this part
            // le = spr.begin()->fi, ri = -spr.begin()->se;
            
            // spr.erase(spr.begin());
            
            // lr = max(lr,ri);
            ri = lr; 
            le = spr.begin()->fi;  
            if(le > lr) { noAns = true; break; }

            // if(ri <= lr || le == ri) continue;
            // if(!spr.empty() && spr.begin()->fi <= lr && -spr.begin()->se >= ri) continue;
            //  cout << le << ' ' << ri << ' ' << ' ' << -spr.begin()->se << ' ' << lr << ' ' << l << ' ' << ans << endl;
            while(!spr.empty() && spr.begin()->fi <= lr){
                ri = max(ri, -spr.begin()->se);
                spr.erase(spr.begin());
            }
            lr = ri;
            // lr = max(lr,ri);
            ++ans;
            if(lr >= l) break;
        }
        if(!noAns && lr >= l && ans) cout << ans << endl;
        else cout << -1 << endl;
    }
}

/*

1. Min > 0
2. Max < l
3. There's a gap

*/