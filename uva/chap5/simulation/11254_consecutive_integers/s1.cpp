#include <iostream>
#include <math.h>
using namespace std;

//AC
int n,first,s,e;
int main(){
    while(scanf("%d", &n), n != -1){
        //10^5*10^3
        s=e=-1;
        for(int i = sqrt(2*n); i > 0; --i){
            first = 2*n - (i-1)*i;
            if(first %(2*i) == 0) { s = first/(2*i), e = s+i-1; break; }
        }
        if(s==e && s==-1) s=e=n;
        printf("%d = %d + ... + %d\n", n, s, e);
    }
}