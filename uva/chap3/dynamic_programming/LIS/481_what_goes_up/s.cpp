#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TLE
typedef vector<int> vi;
#define pb push_back
#define FOR(i,n) for(int i = 0; i < (int)n; ++i) 
int num,n,res, last,k;
vi arr;
void printLIS(int i, int* p, int len){
    if(p[i]== -1 || len == 0){
        cout << arr[i] << endl;
    }
    else {
        printLIS(p[i],p, len-1);
        cout << arr[i] << endl;
    }
}
int main(){
    while(scanf("%d", &num)==1){
        arr.pb(num);
    }
    n = arr.size();
    int p[n];
    int LIS[n];
    FOR(i,n) p[i] = -1, LIS[i] = 1;
    res = 1;
    last = 0;
    FOR(i, n) FOR(j, i) {
        if(arr[i] > arr[j] && LIS[j]+1 >= LIS[i]) {
            p[i] = j, LIS[i] = LIS[j] +1;
            if(LIS[i] >= res) last = i;
            res = max(res, LIS[i]);
        }
        
    }
    cout << res << endl;
    cout << "-\n";
    printLIS(last, p,res);
}