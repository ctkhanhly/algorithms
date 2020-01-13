#include <iostream>
using namespace std;

int main(){
    int cases,w,y1,y2, slideTimes = -101;
    char line;
    cin >> cases;
    while(cases--){
        cin >> line;
        cin >> w;
        while(w--){
            cin >> line;
            cin >> y1 >> y2;
            if(slideTimes == -101) slideTimes = y1 - y2;
            else if(slideTimes != y1 - y2) cout << "no\n"; break;
        }
        cout << "yes\n";
        if(cases >= 1) cout << endl;
    }
}