#include <iostream>
#include <algorithm>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 20000;
int n, m, heads[N], knights[N],gold,j;
bool doomed;
int main(){
    while(scanf("%d %d", &n, &m), n||m){
        FOR(i,n) scanf("%d", &heads[i]);
        FOR(i,m) scanf("%d", &knights[i]);
        gold = 0;
        sort(heads, heads+n);
        sort(knights, knights+m);
        j = doomed = 0;
        FOR(i,n){
            while(j<m && knights[j] < heads[i])++j;
            if(j< m) gold += knights[j++];
            else if(j >= m){ doomed = 1; break;}
        }
        if(doomed) printf("Loowater is doomed!\n");
        else printf("%d\n", gold);
    }
}