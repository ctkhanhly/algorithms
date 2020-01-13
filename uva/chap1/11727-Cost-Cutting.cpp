#include <cstdio>
//#include <math.h> fmax, fmin
using namespace std;
int main(){
    int T, c = 1, x, y, z;//
    scanf("%d", &T);
    while(T-- > 0){
        int min = 10000, max = 1000;
        //scanf("%d%d%d", &x, &y, &z);
        scanf("%d", &x);//1000 to 100000
        if(x > max) max = x;
        if(x < min) min = x;
        scanf("%d", &y);
        if(y > max) max = y;
        if(y < min) min = y;
        scanf("%d", &z);
        if(z > max) max = z;
        if(z < min) min = z;
        int med = (x+y+z) - max - min;
        printf("Case %d: %d\n", c, med);
	++c;
    }
}
/*
#include <stdio.h>

int main() {
    int t, tmp, a, b, c;
    int Case = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &a, &b, &c);
        if(a > c)
            tmp = a, a = c, c = tmp;
        if(b > c)
            tmp = b, b = c, c = tmp;
        if(a > b)
            tmp = a, a = b, b = tmp;
        printf("Case %d: %d\n", ++Case, b);
    }
    return 0;
}
*/