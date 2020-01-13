#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 15;
int n, weights[1<<N], potencies[1<<N], mxSumPo;

int main(){
    while(cin >> n){
        FOR(i, 1<<n) cin >> weights[i], potencies[i] = 0;
        mxSumPo = 0;
        FOR(corner, 1 <<n) FOR(axis, n) potencies[corner] += weights[corner^(1<<axis)]; 
        FOR(corner, 1 <<n) FOR(nei, n) mxSumPo = max(mxSumPo, potencies[corner] + potencies[corner^(1<<nei)]);
        cout << mxSumPo << endl;
    }
}