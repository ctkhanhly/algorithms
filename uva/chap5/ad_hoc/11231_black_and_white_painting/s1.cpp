#include <iostream>
using namespace std;

//AC
int n,m,c;
int main(){
    while(scanf("%d %d %d", &n, &m, &c), n +m + c){
        if(c == 0) cout << (n-7)*(m-7)/2 << endl;
        else cout << ((n-7)*(m-7)+1)/2 << endl;
    }
}