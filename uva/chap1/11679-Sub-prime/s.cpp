#include <iostream>
#define forA(i,n) for(size_t i = 1; i < size_t(n); ++i)
using namespace std;
typedef long int li;

int main(){
    int B, N, D, C, x;
    char ans;
    li R, V;
    while( cin >> B >> N && B!= 0 && N != 0){
        li r[B+1];
        forA(i,B+1) r[i] = 0;
        x = 1;
        while(B--){
            cin >> R;
            r[x++] = R;
        }
        while(N--){
            cin >> D >> C >> V;
            r[D] -= V;
            r[C] +=V;
        }
        ans = 0;
        forA(i, x) if(r[i] < 0) ans = 'N';
        if(ans == 0) ans = 'S';
        cout << ans << '\n';
    }
}