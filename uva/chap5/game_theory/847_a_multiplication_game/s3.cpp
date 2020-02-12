#include <iostream>
#include <math.h>
using namespace std;


//AC
unsigned n,p;
int main(){
    while(scanf("%d", &n)==1){
        p = 1;
        while(p < n) p*=18;
        if(p/2 >= n) printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }
}