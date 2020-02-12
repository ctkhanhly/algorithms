#include <iostream>
using namespace std;

//AC
typedef long long ll;
ll p1,p2;
bool res;
bool play(){
    if(p1> p2) swap(p1,p2);
    //p1*q+r = p2- mult=q-1, p2-p1=r and q1,
    //b,a-b a-b,2b-a 2b-a,-3b+2a -3b+2a,5b-3a
    if(p2%p1 == 0 || p2/p1 >1)
        return 1;
    // cout << p1 << ' ' << p2 << ' ' << res << endl;
    p2 = p2%p1;
    return 0;
}
int main(){
    while(scanf("%lld %lld", &p1, &p2), p1 + p2){
        res = 0;
        while(!play()) res ^= 1;
        if(res) printf("Ollie wins\n");
        else printf("Stan wins\n");
    }
}