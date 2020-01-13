#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 5;
const int M = 1000;
int n, m, mess[N], start[N], sz,res, pacId, p;
unordered_map<int,int> buffer[N];
struct Packet{
    int P, s,e;
};
Packet packets[M];
int main(){
    p = 1;
    //process packet 1, 2,etc
    while(scanf("%d %d", &n,&m), m|| n){
        FOR(z,n) scanf("%d", &mess[z]);
        FOR(i,n) start[i] = 1;
        FOR(i,n) buffer[i].clear();
        sz = res = 0;
        FOR(z,m) {
            scanf("%d %d %d", &packets[z].P, &packets[z].s, &packets[z].e), --packets[z].P;
            if(start[packets[z].P] == packets[z].s) {
                start[ packets[z].P ] = min(packets[z].e+1, mess[packets[z].P]);
            }
            else sz += packets[z].e-packets[z].s +1, buffer[packets[z].P][packets[z].s]= z;
            res = max(res,sz);
            if(buffer[ packets[z].P ].count(packets[z].e+1)){
                pacId = buffer[ packets[z].P ][packets[z].e+1];
                sz -= packets[pacId].e - packets[pacId].s+1;
                buffer[packets[z].P].erase(packets[z].e+1);
            }
        }
        FOR(i,n){
            if(!buffer[i].empty()){
                for(auto it = buffer[i].begin(); it != buffer[i].end(); ++it){
                    pacId = it->second;
                    sz += packets[pacId].e - packets[pacId].s +1;
                }
            }
        }
        res = max(res, sz);
        printf("Case %d: %d\n\n", p, res);
        ++p;
    }
}