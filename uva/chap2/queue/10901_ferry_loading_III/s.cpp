#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10000;
int c,n,t,m, cars[N],round, ncars,span;
bool willWait;
string s;
int main(){
    scanf("%d", &c);
    FOR(z, c){
        scanf("%d %d %d", &n, &t, &m);
        queue<int> left;
        queue<int> right;
        FOR(o,m) {
            // scanf("%d", &cars[o]);
            cin >> cars[o] >> s;
            if(s == "left") left.push(o);
            else right.push(o);
        }
        round = 1;
        span = 0;
        while(!left.empty() || !right.empty()){
            ncars = 0;
            willWait = (right.empty() || cars[right.front()] > span) && (left.empty() || cars[left.front()] > span);
            if(willWait){
                if(!left.empty() && !right.empty()) span = min(cars[right.front()], cars[left.front()]);
                else if(left.empty()) span = cars[right.front()];
                else span = cars[left.front()];
            }
            if(round&1){
                while(!left.empty() && ncars < n){
                    if(cars[left.front()] > span) break;
                    cars[left.front()] = max(span, cars[left.front()]) + t;
                    left.pop();
                    ++ncars;
                }
            }
            else{
                while(!right.empty() && ncars < n){
                    if(cars[right.front()] > span) break;
                    cars[right.front()] = max(span, cars[right.front()]) + t;
                    right.pop();
                    ++ncars;
                }
            }
            span += t;
            ++round;
        }
        if(z) puts("");
        FOR(i,m) printf("%d\n", cars[i]);
    }
}