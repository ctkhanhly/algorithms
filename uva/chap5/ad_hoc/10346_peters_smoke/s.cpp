#include <iostream>
using namespace std;

//AC
int n,k, used;
int main(){
    while(scanf("%d %d", &n, &k) == 2){
        used = k;
        while(used <= n) ++n, used += k;
        //every k cig, I have n/k new cig
        //=> n/k has to eventually reaches 0
        cout << n << endl;
    }
}