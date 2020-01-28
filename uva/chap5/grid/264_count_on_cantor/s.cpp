#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


//AC
int n,r,c,last,side;
int main(){
    while(scanf("%d", &n)==1){
        side = sqrt(2*n);
        last = side*(side+1)/2+1;
        if(last > n) --side;
        r = side+1, c = 1;
        last = side*(side+1)/2+1;
        r -= n-last;
        c += n-last;
        if(side&1) swap(r,c);
        printf("TERM %d IS %d/%d\n", n, r,c);
    }
}