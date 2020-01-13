#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define FOR(i,n) for(int i =0; i < (int)n; ++i)
const int N = 1e6+5;
int p,a,b,c,d,n,i,j,k;
double top, mxDec, currPrice;
int main(){
    while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n)==6){
        top = p * ( sin(a+b) + cos(c+d) + 2);
        mxDec = 0;
        for(int k = 2; k <= n; ++k){
            currPrice = p * ( sin(a*k+b) + cos(c*k+d) + 2);
            //on downhill
            if(top > currPrice) mxDec = max(mxDec, top - currPrice);
            else top = currPrice;//new top, on uphill
        }
        printf("%.8lf\n", mxDec);
    }
}