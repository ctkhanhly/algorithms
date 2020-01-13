#include <iostream>
#include <string> 
#include <math.h>
using namespace std;

int main(){
    int H, D, F, d;//td = total distance
    float td, U,f;
    while(cin >> H >> U >> D >> F && H != 0){
        td = 0;
        d = 0;
        f = U * F / 100;
        while(td >= 0){
            if(U < 0) U = 0;
            td += U;
            U -= f;
            ++d;
            if(td > H) break;
            td -= D;
        }
        if(td < 0) cout << "failure on day " << d << "\n";
        else cout << "success on day " << d << "\n";
    }
}