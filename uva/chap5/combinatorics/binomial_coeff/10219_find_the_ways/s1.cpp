#include <stdio.h>
#include <math.h>
using namespace std;


//AC
int n,k;
long double res;
int main(){
    while(scanf("%d %d", &n, &k)==2){
        res =0;
        for(int i = n; i > n-k; --i) res += log10(i);
        for(int i = 1; i <=k; ++i) res  -= log10(i);
        res++;
        printf("%d\n",  (int)res);
    }
}