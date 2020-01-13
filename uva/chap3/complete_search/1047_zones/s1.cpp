#include <iostream>
// #include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
const int N = 20;
const int M = 10;
int n,to, m,t,c, towers[N], comsT[M], comsC[M], C,cus,p, bmap, res,e;
bool nogo;

int LSOne(int k){ return k&(-k);}
int cntSet(int bitmap){
    int cnt = 0;
    for(int i = bitmap; i > 0; i-=LSOne(i)) ++cnt;
    return cnt;
}
// void printBit(int k){
//     string s;
//     while(k >0) s.pb('0'+k%2), k/=2;
//     reverse(s.begin(), s.end());
//     cout << s << endl;
// }
int main(){
    p = 1;
    while(scanf("%d %d", &n, &to), n || to){
        FOR(i,n) scanf("%d", &towers[i]);
        scanf("%d",&m);
        FOR(i,m) comsT[i] = 0;
        FOR(z,m) {
            scanf("%d",&t);
            FOR(q,t) scanf("%d", &bmap), comsT[z] |= (1 << (bmap-1));
            scanf("%d", &comsC[z]);
        }
        res = C = 0;
        FOR(z, 1 << n){
            if(cntSet(z)!=to) continue;
            cus = 0;
            FOR(i, n) if(z & (1<<i)) cus += towers[i];
            FOR(i,m){
                // nogo = false;
                // FOR(j, n) if(comsT[i] & (1 <<j) && !(z & (1 << j))) { nogo = true; break;}
                // if(!nogo) cus += (cntSet(comsT[i]) & 1 ? 1 : -1)*comsC[i];//inclusion/exclusion principle
                //include only 1 portion of common area among these shared towers
                bmap = comsT[i] & z;
                if(cntSet(bmap) > 0) cus -= (cntSet(bmap)-1)*comsC[i];
            }
            if(cus > C) res = z, C = cus;
        }
        printf("Case Number  %d\n", p);
        printf("Number of Customers: %d\n", C);
        printf("Locations recommended:");
        FOR(i, n) { if(res & (1 << i)) printf(" %d", i+1);}
        printf("\n\n");
        p++;
    }
}