#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;
 
 //AC
typedef long long ll;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 5000;//no bit masking here!!
const ll INF = 25*1e11+100;//(1+2+3+...+5000)1e5 = 25*1e6*1e5 = 25*1e11
int n, num;
ll res,sum,op1,op2;

int main(){
    while(scanf("%d", &n) == 1 && n){
        priority_queue<ll> pq;
        FOR(z,n) scanf("%d", &num), pq.push(-num);
        res = 0;
        while(!pq.empty()){
            op1 = pq.top(), pq.pop();
            op2 = pq.top(), pq.pop();
            // cout << op1 << ' ' << op2 << endl;
            sum = op1 + op2;
            res += sum;
            if(!pq.empty()) pq.push(sum);
        }
        cout << -res << endl;
    }
}