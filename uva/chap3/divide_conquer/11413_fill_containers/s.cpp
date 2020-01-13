#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 1000;
int n,m, vessels[N], lo,hi,mid,curr,numContainers;
bool check(int cap){
    curr = 0, numContainers = 0;
    FOR(i,n) { 
        if(vessels[i] > cap) return false;
        if(curr+vessels[i] > cap) ++numContainers, curr = 0; 
        curr += vessels[i];
    }
    if(curr) ++numContainers;
    // if(numContainers<=m) cout <<cap << ' ' << numContainers << ' ' << m << endl;
    return numContainers <= m;
}
int main(){
    while(scanf("%d %d", &n, &m)==2){
        FOR(i,n) scanf("%d", &vessels[i]);
        lo = 1, hi = 1000000000;//n*c
        while(lo < hi){
            mid = (lo+hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid+1;
        }
        cout << lo << endl;
    }
}