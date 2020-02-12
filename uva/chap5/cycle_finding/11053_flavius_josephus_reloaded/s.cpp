#include <iostream>
using namespace std;


typedef long long ll;
int n, a,b,x,cnt,t,h;
int compute(int num){
    return (a * num * num + b)%n;
}
int main(){
    while(scanf("%d %d %d", &n, &a, &b)==3){
        t = compute(x), h = compute(compute(x));
        while(t != h) t = compute(t), h = compute(compute(h));
        h = compute(t);
        cnt = 1;
        while(t != h) h = compute(h), ++cnt;
        printf("%d\n", n-cnt);
    }
}