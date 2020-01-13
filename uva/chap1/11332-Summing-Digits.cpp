#include <iostream>
using namespace std;

int main(){
    long int n, res = 0;
    while(cin >> n && n != 0){
        res = 0;
        while(n >= 10){
            while(n > 0){
                res += n%10;
                n = n/10;
            }
            n = res;
            res = 0;
        }
        
        cout << n << "\n";
    }
}