#include <iostream>
#include <vector>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
typedef vector<int> vi;
int h, w,T, match[400],r,c,sz,ans,node;//80
char g[45][15];
int dir[] = {0,1,0,-1,0};
bool visited[400];
vi interest;
int augment(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    FOR(k,4){
        int i = u/w + dir[k], j = u%w + dir[k+1];
        if(0 <= i && i < h && 0 <= j && j < w && g[i][j] == '*'){
            if(match[i*w+j] == -1 || augment(match[i*w+j])){
                match[i*w+j] = u;
                match[u] = i*w+j;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        interest.clear();
        scanf("%d %d", &h, &w);
        node = 0;
        FOR(i,h) 
            FOR(j,w) {
            scanf(" %c", g[i]+j);
            //or encode each node to reduce number of nodes
            if(g[i][j] == '*') interest.pb(w*i+j),++node;
        } 
        sz = h*w;
        FOR(i,sz) match[i] = -1;
        ans = 0;
        FOR(i, interest.size()){
            if(match[interest[i]] != -1) continue;
            FOR(j, interest.size()) visited[interest[j]] = 0;
            ans += augment(interest[i]);
        }
        cout << node-ans << endl;
    }
    
}