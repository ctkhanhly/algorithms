#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
// #define LIS(a,b) a<b
// #define LDS(a,b) a>b
const int N = 2000;//ok 10^6
int t,n,res;
int arr[N];
int lis[N], lds[N];

void LIS(){
    for(int i = 0; i < n; ++i){
        lis[i] = 1;
        for(int j = i-1; j >= 0; --j) {
            if(arr[i] > arr[j]) lis[i] = max(lis[i], lis[j]+1);
        }
    }
}
void LDS(){
    for(int i = 0; i < n ; ++i){
        lds[i] = 1;//had to set it here=> my originnal method was wrong
        for(int j = i-1; j >= 0; --j) {
            if(arr[i] < arr[j]) lds[i] = max(lds[i], lds[j]+1);
        }
    }
}
int main(){
    cin >> t;
    FOR(z,t){
        cin >> n;
        FOR(i,n) lis[i] = lds[i] = 0;
        FOR(q, n) cin >> arr[n-q-1];
        res = 0;

        LIS();
        LDS();
        FOR(i, n){
            res = max(res, lds[i]+lis[i]-1);
        }
        cout << res << endl;
    }
}