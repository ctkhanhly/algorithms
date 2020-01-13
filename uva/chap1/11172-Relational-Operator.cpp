#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, a, b;
    cin >> T;
    while(T > 0){
        cin >> a >> b;
        if(a > b) cout << ">";
        else if(a < b) cout << "<";
        else cout << "=";
        if(T!= 0) cout << "\n";
        --T;
    }
}