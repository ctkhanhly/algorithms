#include <iostream>
#include <unordered_set>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int N,M,num,ans;
unordered_set<int> Jack;
int main(){
    while(cin >> N >> M, N || M){
        ans = 0;
        Jack.clear();
        FOR(i,N) {cin >> num;  Jack.insert(num);}
        FOR(i,M) { cin >> num; if(Jack.count(num)) ++ans;}
        cout << ans << endl;
    }
}