#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 5, M = 1000;
int n, m, mess[N], p,order[N],sz,res,start[N],pacLen,mxBuff, pacId, lstart;
unordered_map<int,int> buff[N];
struct Packet{
    int P, s,e;
};
Packet* packets[M];
bool processed[N];
ostream& operator<<(ostream& os, const Packet& p){
    os << p.P << ' ' << p.s << ' ' << p.e << endl;
    return os;
}
int main(){
    p = 1;
    while(scanf("%d %d", &n, &m), n || m){
        res = 0;
        FOR(z, n) scanf("%d", &mess[z]), res += mess[z];
        FOR(i, m) packets[i] = new Packet, scanf("%d %d %d", &packets[i]->P, &packets[i]->s, &packets[i]->e), --packets[i]->P;

        FOR(i,n) order[i] = i;
        do{
            sz = 0;
            FOR(i,n) start[i] = 1, buff[i].clear(), processed[i] = false;
            mxBuff = 0;
            FOR(i,n){
                pacId = order[i];
                FOR(j,m){
                    pacLen = packets[ j ]->e - packets[ j]->s +1;
                    if(packets[j]->P == pacId && packets[j]->s == start[pacId]) {
                        if(!buff[pacId].count(start[pacId])) start[pacId] = packets[j]->e+1;
                        while(buff[pacId].count(start[pacId])){
                            sz -= buff[pacId][start[pacId]] - start[pacId] +1;
                            lstart = start[pacId];
                            start[pacId] = buff[pacId][start[pacId]]+1;
                            buff[pacId].erase(lstart);
                        }
                        if(start[pacId] > mess[pacId]) break;
                    }
                    else if(!processed[packets[j]->P] && !buff[packets[j]->P ].count(packets[j]->s)) {
                        buff[packets[j]->P ][packets[j]->s] = packets[j]->e, sz += pacLen;
                    }
                    mxBuff = max(mxBuff, sz);
                }
                processed[pacId] = true;
            }
            
            res = min(res, mxBuff);
        }while(next_permutation(order, order+n));
        printf("Case %d: %d\n\n", p, res);
        ++p;
    }
    
}