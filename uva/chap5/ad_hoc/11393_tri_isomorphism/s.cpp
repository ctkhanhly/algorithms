#include <iostream>
using namespace std;


int n;
int main(){
    while(scanf("%d", &n), n){
        if(n == 1 || n%3 == 2) cout << "NO\n";
        else cout << "YES\n";
    }
}