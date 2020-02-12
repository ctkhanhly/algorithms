#include <iostream>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int t, m,n,r,c, piles;
int main(){
    scanf("%d", &t);
    FOR(z,t){
        scanf("%d %d %d %d", &m, &n, &r, &c);
        piles = (m-1-r)^r^c^(n-1-c);
        if(piles) printf("Gretel\n");
        else printf("Hansel\n");
    }
}
//https://github.com/be-oi/beoi-training/tree/master/25-game-theory
//https://math.stackexchange.com/questions/416042/why-xor-operator-works
//win to lose: choose a move so that no matter what opponent does, he/she will lose
/*
if Alice in a state where n= 3, Alice loses
For a state 2^n-1:
whatever Alice takes, Bob takes the composite to remove 1s @ higher bits, so A always faces with 

2^n-1 state
*/