#include <iostream>
#include <algorithm>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 8;
int t,n, g[N][N],currScore, score;
int pick[N];

//brute force: n!*n! = 8!*8! = 10^10 => impossible!
int main(){
    scanf("%d",&t);
    FOR(z,t){
        scanf("%d", &n);
        FOR(i,n) FOR(j, n) scanf("%d", &g[i][j]); 
        FOR(i, n) pick[i] = i;
        score = 1e4;
        do{
            currScore = 0;
            //Bob knows the optimal perm he should play
            //whatever row A picks=> B picks according to this worst perm
            FOR(i, n) currScore += g[i][ pick[i] ];
            score = min(score, currScore);
        }while(next_permutation(pick, pick+n));
        cout << score << endl;
    }
}
