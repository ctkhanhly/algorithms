#include <iostream>
#include <math.h>
using namespace std;

//AC
#define EPS 1e-9

double lo,hi,mid,ans;
int p,q,r,s,t,u;

double compute(double x){
    return (double)p * exp(-x) + (double)q * sin(x) + (double)r *cos(x) + (double)s * tan(x) + (double)t * x * x + (double)u;
}
int main(){
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)==6){
        //f starts out >= 0, increase x f goes down until x = 1
        //=> min f has to be <= EPS~~0 line, max x has to start out above 0 line(integers) => >= EPS
        if(compute(1.0) > EPS || compute(0) < 0.0) {
            printf("No solution\n");
            continue;
        }
        lo = 0.0000, hi = 1.0000, ans = -1.0000;
        for(int i = 0; i < 30; ++i){
            mid = (lo+hi)/2.0;
            //increase x = > negative, 0-1: sinx,cosx,tanx >0, q,r,s < 0

            if((compute(mid) > 0.0)) lo = mid;
            else hi = mid;
        }
        printf("%.4lf\n", hi);//either hi or lo b/c both are in error range <= EPS
        
    }
}