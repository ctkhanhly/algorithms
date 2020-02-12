#include <iostream>
using namespace std;


//AC
int z,i,m,l,t,h,idx,idx2,cs;
int compute(int a){
    return (z*a+i)%m;
}
int main(){
    cs = 1;
    while(scanf("%d %d %d %d", &z, &i, &m, &l), z+i+m+l){
        t = compute(l), h = compute(compute(l));
        idx = 1;
        while(t != h) t = compute(t), h = compute(compute(h)), ++idx; 
        idx2 = idx;
        h = compute(t), ++idx2;
        while(t!= h) h = compute(h), ++idx2;
        printf("Case %d: %d\n", cs, idx2-idx);
        ++cs;
    }
}