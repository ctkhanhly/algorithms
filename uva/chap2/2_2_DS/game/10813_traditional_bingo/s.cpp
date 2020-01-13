#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int DIM = 5;
const int MXNUM = 75;
const int FREE = 2;
int card[DIM][DIM], num, rows[DIM], cols[DIM];
int n,col,seq, lDiag, rDiag;
bool bingo;
int main(){
    scanf("%d", &n);
    FOR(z, n){
        FOR(r, DIM) FOR(c, DIM) if(r == 2 && c == 2) continue; else scanf("%d",&card[r][c]);
        card[FREE][FREE] = 0;
        bingo = false;
        FOR(i,DIM) rows[i] = cols[i] = 0;
        lDiag = rDiag = rows[FREE] = cols[FREE] = 1;
        FOR(i, MXNUM){
            scanf("%d", &num);
            // cout << num << endl;
            if(!bingo){
                col = (num-1)/15;
                seq = 0;
                FOR(r,DIM) if(card[r][col] == num){ 
                    card[r][col] = 0; 
                    ++rows[r], ++cols[col];
                    if(r == col) ++lDiag;
                    else if(r+col == DIM-1) ++rDiag;
                    if(rows[r] == DIM || cols[col] == DIM || lDiag == DIM || rDiag == DIM) bingo = true;
                    break;
                }
                if(bingo) printf("BINGO after %d numbers announced\n", i+1);
            }
        }
    }
}