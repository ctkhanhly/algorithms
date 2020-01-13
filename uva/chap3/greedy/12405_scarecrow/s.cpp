#include <iostream>
using namespace std;
 

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
int T, n, field[N],lstart,ans;
char c;
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d", &n);
        getchar();
        // cout << n << endl;
        FOR(i,n) scanf("%c", &c),field[i] = c=='.'? 1 : 0;
        // cout << endl;
        lstart = -2;
        ans = 0;
        // FOR(i,n) cout << field[i] << ' ';
        // cout << endl;
        FOR(i,n){ 
            if(field[i] && i > lstart+1) lstart = i+1< n? i+1 : i, ++ans;
        }
        printf("Case %d: %d\n", z+1, ans);
    }
}