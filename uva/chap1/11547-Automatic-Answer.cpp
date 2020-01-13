#include <iostream>
using namespace std;

int main(){
    int T, n;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        cout << abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10) << "\n"; 
    }
}
