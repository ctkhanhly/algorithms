#include <iostream>
#include <math.h>
using namespace std;


typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
ll n,c1,n1,c2,n2,x,y,d,c,s,e, x2,y2,cost, ans1,ans2;
ll op1, op2;

void extendedEuclid(ll a, ll b){
    if(b == 0) { x=1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main(){
   while(scanf("%lld", &n),n){
        scanf("%lld %lld", &c1, &n1);
        scanf("%lld %lld", &c2, &n2);
        extendedEuclid(n1,n2);
        if(n%d == 0){
            x*= n/d, y *= n/d;
            op1 = ceil(-(double)x *d / n2);
            op2 = floor((double)y * d / n1);
            
            // if(x < 0) s = ceil(op1), e = op2;
            // else s = ceil(op2), e = op1;
            ans1 = ans2 = -1;
            if(op1 <= op2){
                cost = max(c1,c2)*n;
                // cout << x << ' ' << d << ' ' << y << ' ' << op1 << ' ' << op2 << endl;
                for(int i = op1; i <= op2; ++i){
                    x2 = x + (n2/d)*i;
                    y2 = y - (n1/d)*i;
                    if(x2 >= 0 && y2 >= 0 && x2*c1 + y2*c2 < cost)
                        cost = x2*c1 + y2*c2, ans1 = x2, ans2 = y2;
                }
                if(ans1 >= 0 && ans2 >=0){ printf("%lld %lld\n", ans1,ans2); continue;}
            }
            
        }
        printf("failed\n");
    }
}

/*
c1*x + c2*y = cost
x*n1 + y*n2 = n
x = x+(b/d)n;
y = y + (a/d)n;
=> min(n) = min cost

prove correctness for euclid function by solving:
r = x1* a -y1*b
r' = bx + y*r
*/