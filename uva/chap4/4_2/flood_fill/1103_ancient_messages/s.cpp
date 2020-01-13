#include <iostream>
#include <bitset>
using namespace std;

// #define A 1
// #define J 3
// #define D 5
// #define S 4
// #define W 0
// #define K 2

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
typedef enum{WH, BL, BOR} pixels;
typedef vector<char> vc;
const int H = 200;
int h,w,T,row, numCC, ind;
// bitset<H> img[H];
pixels img[H][H];
char hierog[6] = {'W','A','K', 'J', 'S', 'D'};
int dir[5] = {0,-1,0,1,0};
int dir8[9] = {0,-1,0,1,1,-1,-1,1,0};
string res;

int floodFill(int r, int c, pixels p){
    int numCC = 0;
    img[r][c] = BOR;
    FOR(k, 4){
        int i = r + dir[k], j = c + dir[k+1];
        if(0<=i && i < h && 0 <= j && j < 4*w){
            if(p == BL){
                if(img[i][j] == BL) floodFill(i,j, BL);
                else if(img[i][j] == WH) ++numCC,floodFill(i,j, WH);
            }
            else if(img[i][j] == WH) floodFill(i,j, p);
        }
    }
    return numCC;
}
int main(){
    while(cin >> h >> w && (h || w)){
        res.clear();
        FOR(p,h){
            cin >> hex >> row;
            cout << dec << row << ' ' << hex << row<< endl;
            FOR(o, 4*w){
                img[p][o] = (row&(1 << o));
            }
        }
        // FOR(p,h) {FOR(o, 4*w) cout << img[p][o] << ' '; cout << endl;}
        FOR(p,h) if(img[p][0] == WH) floodFill(p,0, WH);
        //at least 1 black pixel => first column => W of this row > other rows
        //=>  needs  a bigger W => first columns will be 0
        FOR(p,h) if(img[p][0] == WH) floodFill(p,0, BOR); else if(img[p][4*w-1] == WH) floodFill(p,w*4-1, BOR);
        FOR(o,w) if(img[0][0] == WH) floodFill(0,o, BOR); else if(img[h-1][o] == WH) floodFill(h-1,o, BOR);
        FOR(p,h) {FOR(o, 4*w) cout << img[p][o] ; cout << endl;}
        int cnt = 1;
        FOR(p,h){
            FOR(o,4*w){
                //floodFill(p,o, BL)
                if(img[p][o] == BL && cnt == 1) {
                    int ind = floodFill(p,o, BL);
                    cout << ind << endl;
                    res.push_back(hierog[ind]);
                    ++cnt;
                }
            }
        }
        cout << res << endl;
    }
}
/*
001110000 = 70
011011000 = d8
010001000 = 88
011011000 = d8
001110000 = 70
011111100 = fc
001010000 = 50
001010000 = 50

*/