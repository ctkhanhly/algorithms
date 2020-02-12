#include <stdio.h>
using namespace std;


//~~~parentheses app
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int cat[15],n,z;
int main(){
    FOR(i,15) cat[i] = 0;
    cat[0] = 1;
    for(int i = 0; i < 14; ++i) cat[i+1] = (2*i+2)*(2*i+1)*cat[i]/((i+2)*(i+1));
    z = 0;
    while(scanf("%d", &n) ==1){
        if(z) puts("");
        printf("%d\n", cat[n]);
        ++z;
    }
}