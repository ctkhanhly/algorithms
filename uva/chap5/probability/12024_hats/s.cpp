#include <iostream>
using namespace std;


//AC
int n, fact[13], d[13],t;
int main(){
    d[1] = 0, d[2] = 1;
    fact[1]=1, fact[2]=2;
    for(int i = 3; i <=12; ++i)
        fact[i] = i*fact[i-1], d[i]=(i-1)*(d[i-1]+d[i-2]);
    scanf("%d", &t);
    for(int i = 0; i <  t; ++i){
        scanf("%d",&n);
        printf("%d/%d\n", d[n], fact[n]);
    }
}