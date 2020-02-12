#include <iostream>
using namespace std;



//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int t, n, x;
double p,w,res;
int main(){
    scanf("%d", &t);
    FOR(z,t){
        scanf("%d",&n);
        res = w = 0;
        FOR(i,n) {
            scanf("%d %lf", &x, &p);
            if(x > 0) res += x*p, w += p;
            else res -= x*p;
        }
        /*
        Imagine you walk indefinitely and stop at some huge K
        now w of time, you walk into a room that leads to a safe room
        total time: x_i*(K*p_i) for each i
        => divide to K*w situations = average time of each situation
        */
        printf("Case %d: ",z+1);
        if(w < 1e-9) printf("God! Save me\n");
        else printf("%.2lf\n", res/w);
    }
}