#include <iostream>
#include <queue>
#include <string>
using namespace std;


//AC
#define fi first
#define se second
typedef pair<int,int> ii;
int n, K, clk,q,p,i,t;
string s;
struct Argus{
    int p,q,t;
};
bool operator<(const Argus& a1, const Argus& a2){
    return a1.t == a2.t ? a1.q < a2.q : a1.t < a2.t;
}
int main(){
    priority_queue<Argus> pq;
    while(cin >> s && s != "#"){
        scanf("%d %d", &q, &p);
        pq.push({-p,-q,-p});
    }
    cin >> K;
    i = 0;
    while(i < K && ! pq.empty()){
        p = pq.top().p, q = pq.top().q, t = pq.top().t;
        pq.pop();
        cout << -q << endl;
        pq.push({p,q,t+p});
        ++i;
    }
}