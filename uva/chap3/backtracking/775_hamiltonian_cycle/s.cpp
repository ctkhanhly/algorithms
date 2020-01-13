#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

//AC
typedef pair<int,int> ii;
typedef vector<int> vi;
#define U -1
#define E 0
#define V 1
#define pb push_back
#define FOR(i,n) for(int i =0; i < (int)n; ++i)
const int N = 256;
int n,u,v, status[N], p[N],vnum;
bool found;
char e;
vi g[N];

void printCycle(int s){
    if(p[s] == s) printf("%d", s+1);
    else{
        printCycle(p[s]);
        printf(" %d", s+1);
    }
}

//T(n) = T(n-1) + O(n) = O(n^2)
void walk(int s){
    if(found) return;
    status[s] = E;
    FOR(j, g[s].size()){
        if(status[ g[s][j] ] == U) p[ g[s][j] ] = s, walk(g[s][j]), status[ g[s][j] ] = U;
        else if(status[ g[s][j] ] == E && p[ g[s][j] ] == g[s][j]){
            vnum = 1, u = s;
            while(u != p[u]) ++vnum, u = p[u];
            if(vnum == n){
                found = true;
                printCycle(s);
                printf(" %d", g[s][j]+1);
                return;
            }
        }
        if(found) return;
    }   
    status[s] = U;
}

int main(){
    while(scanf("%d", &n) ==1 ){
        FOR(z,n) g[z].clear(), status[z] = U, p[z] = z;
        while(scanf("%d %d", &u, &v)==2) g[--u].pb(--v), g[v].pb(u);
        scanf("%c", &e);
        found = false;
        walk(0);
        // FOR(i,n) if(!found) memset(status, U, sizeof status), walk(i);
        if(!found) printf("N\n");
        else puts("");
    }
}