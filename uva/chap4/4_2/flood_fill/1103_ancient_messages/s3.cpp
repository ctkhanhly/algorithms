#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
// #include <bits/stdc++.h> 
using namespace std;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)

#define WH 0
#define BL 1
const int H = 200;
const int W = 50;
int h,w,T,row, numCC, ind,cs;
int img[H][H];
int contour[H][H];
string hierog = "gWAKJSD";
string res;
string rew;
char rew2[W];
int dir[5] = {0,-1,0,1,0};
bool in(int i, int j) { return  0 <= i  && i < h && 0 <= j && j < 4*w;}
void dfs(int r, int c, bool isImg){
    if(isImg){
        contour[r][c] = WH;
        img[r][c] = WH;
    }
    else contour[r][c] = WH;
    FOR(k, 4){
        int i = r + dir[k], j = c + dir[k+1];
        if(isImg && in(i,j) && img[i][j] == BL) dfs(i,j, isImg);
        else if(!isImg && in(i,j) && contour[i][j]) dfs(i,j, isImg);
    }
}
void cc(){
    int numCC = 0;
    // FOR(i, h) FOR(j,4*w) contour[i][j] = !contour[i][j];
    // now all white regions are 1
    FOR(i, h) FOR(j, 4*w) if(contour[i][j]) dfs(i,j,false), ++numCC;
    res.push_back(hierog[numCC]);
}
int main(){
    cs = 1;
    while(cin >> h >> w, h+w){
        if(cs > 1) cout << endl;
        res.clear();
        // if(cs == 1) getline(cin, rew);
        FOR(p,h){
            cin >> std::hex >> row;
            // getline(cin, rew);
            // scanf()
            // cout << rew  << ' ' << (rew == "")<< endl;
            // row = stoi(rew,nullptr,16);
            FOR(o, 4*w){
                img[p][o] = (row&(1 << (4*w-o))) ? BL : WH;
            }
        }

        FOR(p,h){
            FOR(o,4*w){
                if(img[p][o] == BL) {
                    // FOR(i, h) FOR(j,4*w) contour[i][j] = 0;
                    memset(contour, 1, sizeof(contour));
                    dfs(p,o, true);
                    cc();
                }
            }
        }
        sort(res.begin(), res.end());
        printf("Case %d: ", cs);
        cout << res;
    }
}