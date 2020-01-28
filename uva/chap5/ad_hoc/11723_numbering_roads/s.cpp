#include <iostream>
using namespace std;

//AC
int r,n,z, res;
int main(){
    z = 1;
    while(scanf("%d %d", &r, &n), r || n){
        // cout << r << ' ' << n << endl;
        printf("Case %d: ", z);
        res = r/n - (r%n == 0);
        if(0<= res && res <= 26) printf("%d\n", res);
        else printf("impossible\n");
        z++;
    }
}