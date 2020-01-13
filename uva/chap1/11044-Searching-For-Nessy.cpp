#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, n, m;
    cin >> T;
    int count = 0;
    while(T-- > 0){
        //if(count) cout << "\n";
        cin >> n >> m;
        cout << (n/3)*(m/3) << "\n";
        ++count;
    }
}