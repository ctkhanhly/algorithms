#include <iostream>
#include <string>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)

const int N = 10;
char arr[N], n,z;
string s;
void backtrack(int i){
    if(i == n){
        FOR(j,n) cout << arr[j];
        cout << endl;
    }
    else{
        for(int j = i; j >= 1; --j) arr[j] = arr[j-1];
        for(int j = 0; j <= i; ++j){
            arr[j] = s[i];
            backtrack(i+1);
            if(j+1 < n) arr[j] = arr[j+1];
        }
    }
}
int main(){
    z = 0;
    while(cin >> s){
        if(z) cout << endl;
        n = s.size();
        backtrack(0);
        ++z;
    }
}