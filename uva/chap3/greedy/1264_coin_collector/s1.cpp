#include <iostream>
using namespace std;

//AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 1000;
int n, coins[N], T, numCoins;
ll sum;
int main(){
    scanf("%d", &T);
    FOR(z, T){
        scanf("%d", &n);
        FOR(i,n) scanf("%d", &coins[i]);
        sum = numCoins = 0;
        FOR(i,n){
            if(i+1 < n && sum + coins[i] < coins[i+1]) sum+= coins[i], ++numCoins;
        }
        //for last coin
        cout << numCoins+1 << endl;
    }
}