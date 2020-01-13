#include <iostream>
using namespace std;

int main(){
    int T, N, H, l, h, lH, c = 1;//last height
    cin >> T;
    while(T--){
        cin >> N;
        lH = 0, l = 0, h = 0;
        while(N--){
            cin >> H;
            if(lH > 0 && H > lH) ++h;
            else if(H < lH) ++l;
            lH = H;
        }
        cout << "Case " << c++ << ": " << h << ' ' << l << "\n";
    }
}