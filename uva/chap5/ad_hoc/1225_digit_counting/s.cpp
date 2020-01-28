#include <iostream>
#include <string>
using namespace  std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int T, n, arr[10],n1;
string num;
void cntDigits(const string& k){
    for(int i = 0; i < k.size(); ++i)
        ++arr[k[i]-'0'];
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d", &n);    
        FOR(i,10) arr[i] = 0;
        n1 = 1;
        while(n1 <= n) num = to_string(n1), cntDigits(num), ++n1;
        FOR(i,10) { printf("%d", arr[i]); if(i < 9) printf(" "); else printf("\n");}
        // cout << z << ' ' << n s<< endl;
    }
}