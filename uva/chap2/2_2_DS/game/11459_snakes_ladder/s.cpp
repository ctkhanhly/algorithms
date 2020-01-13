#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int LABELS = 100;
const int PLAYERS = 1e6;
int t,a,b,c, mouth, tail, roll, playerId;
int grid[LABELS+1];
int players[PLAYERS];
bool endOfGame;
int main(){
    cin >> t;
    FOR(z,t){
        cin >> a >> b >> c;
        FOR(i, LABELS) grid[i] = 0;
        FOR(k, b) cin >> mouth >> tail, grid[mouth] = tail;
        FOR(i,a) players[i] = 1;
        endOfGame = false;
        FOR(k,c){
            cin >> roll;
            if(!endOfGame){
                playerId = k%a;
                players[playerId] = min(players[playerId]+roll, 100);
                if(grid[players[playerId]])  players[playerId] = grid[players[playerId]];
                if(players[playerId] == 100) endOfGame = true;
            }
            
        }
        FOR(i, a) printf("Position of player %d is %d.\n", i+1, players[i]);
    }
}