#include <iostream>
#include <math.h>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define EPS 1e-9
double d,v,u;
int T;
int main(){
    scanf("%d", &T);
    FOR(z,T){
        //v = 0, not possible
        scanf("%lf %lf %lf", &d, &v, &u);
        printf("Case %d: ", z+1);
        if(abs(v) <= EPS || u <= v ) printf("can't determine\n");
        else printf("%.3lf\n", d/sqrt(u*u-v*v) - d/u );
    }
}