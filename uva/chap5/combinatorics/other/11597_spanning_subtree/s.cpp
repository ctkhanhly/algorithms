#include <stdio.h>
using namespace std;


//AC
int n,z;
int main(){
    z = 1;
    while(scanf("%d", &n), n){
        printf("Case %d: %d\n", z, n/2);
        ++z;
    }
}