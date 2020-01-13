#include <iostream>
#include <bitset>
using namespace std;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)

#define WH 0
#define BL 1
typedef vector<char> vc;
const int H = 200;
int h,w,T,row, numCC, ind;
// bitset<H> img[H];
int img[H][H];
bitset<H> contour[H];
// char hierog[6] = {'W','A','K', 'J', 'S', 'D'};
string hierog = "gWAKJSD";
string res;
int dir[5] = {0,-1,0,1,0};
bool in(int i, int j) { return  0 <= i  && i < h && 0 <= j && j < w;}
void dfs(int r, int c, bool isImg){
    if(isImg){
        contour[r].set(c);
        img[r][c] = WH;
    }
    else contour[r].reset(c);
    FOR(k, 4){
        int i = r + dir[k], j = c + dir[k+1];
        if(isImg && in(i,j) && img[i][j]) dfs(i,j, isImg);
        else if(in(i,j) && contour[i][j]) dfs(i,j, isImg);
    }
}
void cc(){
    int numCC = 0;
    FOR(i, h) contour[i].flip();// now all white regions are 1
    // FOR(i,h) cout << contour[i] << endl;
    cout << endl;
    FOR(i, h) FOR(j, 4*w) if(contour[i].test(j)) dfs(i,j,false), ++numCC;
    res.push_back(hierog[numCC]);
}
int main(){
    while(cin >> h >> w, h+w){
        res.clear();
        FOR(p,h){
            cin >> hex >> row;
            // cout << dec << row << ' ' << hex << row<< endl;
            FOR(o, 4*w){
                img[p][o] = (row&(1 << o)) ? BL : WH;
            }
        }
        FOR(p,h){
            FOR(o,4*w){
                //floodFill(p,o, BL)
                if(img[p][o] == BL) {
                    // int ind = floodFill(p,o, BL);
                    // cout << ind << endl;
                    // res.push_back(hierog[ind]);
                    // cout << p << ' ' << o << endl;
                    FOR(i,h) contour[i].reset();
                    dfs(p,o, true);
                    cc();
                    // FOR(i,h) {FOR(j, 4*w) cout << img[i][j] << ' '; cout << endl;}
                    // cout << endl;
                }
            }
        }
        cout << res << endl;
    }
}