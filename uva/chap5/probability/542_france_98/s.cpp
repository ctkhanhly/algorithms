#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;



//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
double wins[16], win2[16];
double p[16][16], prob;
unordered_map<string,int> converter;
string names[16],s;
int curr;
int main(){
    for(int i = 0; i < 16; ++i){
        cin >> s;
        converter[s] = i;
        names[i] = s;
    }
    FOR(i,16) FOR(j,16) cin >> p[i][j],p[i][j]/=100;
    FOR(i,16) wins[i] = p[i][i&1 ? i-1 : i+1];//, cout << wins[i] << ' ';
    // cout << endl;
    for(int round = 1; round <= 3; ++round){
        for(int i = 0; i < 16; ++i){
            curr = i/pow(2,round);
            curr = curr&1 ? curr-1 : curr+1;
            curr *= pow(2,round);
            win2[i] = 0;
            // cout << i << ' ' << curr << ' ' << round << ' ';
            for(int j = curr; j < curr + pow(2,round); ++j){
                // cout << prob << ' ' << j << endl;
                win2[i] += p[i][j]*wins[j];
            }
            win2[i] *= wins[i];
            // cout << ' ' << win2[i] << endl;
        }
        copy(win2, win2+16, wins);
    }
    FOR(i,16) printf("%-10s p=%.2lf%%\n", names[i].c_str(), wins[i]*100);
}