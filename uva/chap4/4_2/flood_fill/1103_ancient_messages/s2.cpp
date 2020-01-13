#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)

#define WH 0
#define BL 1
typedef vector<char> vc;
const int H = 200;
int h,w,T,row, numCC, ind,cs;
// bitset<H> img[H];
int img[H][H];
int contour[H][H];
// char hierog[6] = {'W','A','K', 'J', 'S', 'D'};
string hierog = "gWAKJSD";
string res;
int dir[5] = {0,-1,0,1,0};
bool in(int i, int j) { return  0 <= i  && i < h && 0 <= j && j < 4*w;}
void dfs(int r, int c, bool isImg){
    if(isImg){
        contour[r][c] = BL;
        img[r][c] = WH;
        // cout << r << ' ' << c << endl;
    }
    else contour[r][c] = WH;
    FOR(k, 4){
        int i = r + dir[k], j = c + dir[k+1];
        // cout << i << ' ' << j << ' ' << img[i][j] << endl;
        if(isImg && in(i,j) && img[i][j] == BL) dfs(i,j, isImg);
        else if(!isImg && in(i,j) && contour[i][j]) dfs(i,j, isImg);
    }
}
void cc(){
    int numCC = 0;
    #ifdef DEBUG
    FOR(i,h) {FOR(j, 4*w) cout << contour[i][j] << ' '; cout << endl;}
    cout << endl;
    #endif

    FOR(i, h) FOR(j,4*w) contour[i][j] = !contour[i][j];
    // now all white regions are 1

     #ifdef DEBUG
    FOR(i,h) {FOR(j, 4*w) cout << contour[i][j] << ' '; cout << endl;}
    cout << endl;
    #endif

    FOR(i, h) FOR(j, 4*w) if(contour[i][j]) dfs(i,j,false), ++numCC;
    #ifdef DEBUG
    cout << numCC << endl;
    #endif
    res.push_back(hierog[numCC]);
}
int main(){
    cs = 1;
    while(cin >> h >> w, h+w){
        if(cs > 1) cout << endl;
        res.clear();
        FOR(p,h){
            cin >> hex >> row;
            #ifdef DEBUG
            cout << dec << row << ' ' << hex << row<< endl;
            #endif
            FOR(o, 4*w){
                img[p][o] = (row&(1 << (4*w-o))) ? BL : WH;
            }
        }
        #ifdef DEBUG
        FOR(i,h) {FOR(j, 4*w) cout << img[i][j] << ' '; cout << endl;}
        cout << endl;
        #endif

        FOR(p,h){
            FOR(o,4*w){
                //floodFill(p,o, BL)
                if(img[p][o] == BL) {
                    // int ind = floodFill(p,o, BL);
                    // cout << ind << endl;
                    // res.push_back(hierog[ind]);
                    // cout << p << ' ' << o << endl;
                    // FOR(i,h) contour[i].reset();
                    memset(contour, 0, sizeof(contour));
                    // FOR(i,h) FOR(j, 4*w) contour[i][j] = 0;
                    dfs(p,o, true);
                    cc();
                    // FOR(i,h) {FOR(j, 4*w) cout << img[i][j] << ' '; cout << endl;}
                    // cout << endl;
                }
            }
        }
        sort(res.begin(), res.end());
        printf("Case %d: ", cs);
        cout << res;
    }
}