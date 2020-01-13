#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, count = 0, x, c = 1;
    while(cin >> N && N != 0){
        count = 0;
        while(N--){
            cin >> x;
            x ? ++count : --count;
        }
        cout << "Case " << c << ": " << count << "\n"; 
        ++c;
    }
    
    
}