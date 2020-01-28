#include <iostream>
using namespace std;

//AC

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define X 0
#define Y 1
const int N = 100005;
int n, k, layer, rep,x,y, rounds;
int dir[6][2] = { {0,1}, {-1,1}, {-1,0}, {0,-1}, {1,-1}, {1,0}};
int converter[N][2];
int main(){
    n = 1;
    layer = 1, k = rep = 0;
    converter[n][X] = x = 0, converter[n++][Y] = y = 0;
    while(n < N){
        if(k == 1) rounds = layer-1;
        else rounds = layer;
        while(rep < rounds && n < N) {
            x += dir[k][X], y += dir[k][Y];
            converter[n][X] = x, converter[n++][Y] = y;
            ++rep;
        }
        rep = 0;
        ++k;
        if(k == 6) k = 0, ++layer;
    }
    while(scanf("%d", &n) == 1){
        printf("%d %d\n", converter[n][X], converter[n][Y]);
    }
}