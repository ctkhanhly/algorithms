#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int P = 20;
int n, bars[P],p,t;
bool used[P];
//O(20^2)+O(19^2) etc = O(20*20^2)= O(20^3) ok
bool backtrack(int tot, int i){
    if(tot == n) return true;
    if(i == p) return tot == n;
    bool ans = 0;
    for(int j = i; j < p; ++j){
        if(tot + bars[j] > n) continue;
        if(!used[j]){
            used[j] = 1;
            ans |= backtrack(tot + bars[j], j+1);
            used[j] = 0;
        }
    }
    return ans;
}
int main(){
    scanf("%d", &t);
    FOR(z,t){
        scanf("%d %d", &n, &p);
        FOR(i,p) scanf("%d", &bars[i]), used[i] = false;
        if(backtrack(0,0)) printf("YES\n");
        else printf("NO\n");
    }
}