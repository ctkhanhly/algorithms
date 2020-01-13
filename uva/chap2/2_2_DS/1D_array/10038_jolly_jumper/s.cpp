#include <iostream>
#include <math.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 3001;
int n, a,b;
bool notJolly;
bool jollCheck[N];
int main(){
    while(cin >> n){
        notJolly = false;
        FOR(i,n) jollCheck[i] = 0;
        FOR(i,n) {
            cin >> a; 
            if(i) jollCheck[abs(a-b)] = 1;
            b = a;
        }
        FOR(i,n) if(i && !jollCheck[i]) notJolly = true;
        if(notJolly) cout << "Not jolly" << endl;
        else cout << "Jolly" << endl;
    }
}