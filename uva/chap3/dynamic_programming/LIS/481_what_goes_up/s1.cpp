#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//AC
typedef vector<int> vi;
#define pb push_back
#define eb emplace_back
#define FOR(i,n) for(int i = 0; i < (int)n; ++i) 
int num,n,pos,last;
vi arr,lis;

void printLIS(int i, int* p){
    // cout << i << endl;
    if(i == -1) return;
    printLIS(p[i],p);
    cout << arr[i] << endl;
}
int main(){
    while(scanf("%d", &num)==1){
        arr.pb(num);
    }
    n = arr.size();
    int p[n],idx[n];
    FOR(i,n) p[i] = idx[i] = -1;

    FOR(i, n) {
        if(lis.empty() || arr[i] > lis.back()) {
            pos = lis.size();
            lis.eb(arr[i]);
        }
        else{
            //cannot store index at each length because
            //multiple elements maybe in the same index 
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            pos = it-lis.begin();
            lis[pos] = arr[i];
            //there maybe multiple that points to idx-1
        }
        idx[pos] = i;
        if(pos == lis.size()-1) last = i;
        p[i] = pos ? idx[pos-1]: -1;
    }
    cout << lis.size() << endl;
    cout << "-\n";
    printLIS(last, p);
}