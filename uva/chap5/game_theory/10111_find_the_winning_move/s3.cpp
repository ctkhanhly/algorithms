#include <iostream>
#include <string>
using namespace  std;

//AC
#define FOR(i,n) for(int i  = 0; i < (int)n; ++i)
char ch;
int r,c, row[4], col[4], diag[2],adva;
string g[4];
char moves[] = {'x', 'o'};
int wins[] = {1,-1};
bool check(int p){
    FOR(i,4) {
        if(row[i] == 4*p|| col[i] == 4*p) return 1;
    }
    if(diag[0] == 4*p || diag[1] == 4*p) return 1;
    return 0;
}
void update(int p, bool backtr, int i, int j){
    if(backtr) g[i][j] = '.';
    else g[i][j] = moves[p == -1 ? 1: 0];

    adva = (p==-1 && backtr) || (p==1 && !backtr) ? 1 : -1;
    row[i] += adva;
    col[j] += adva;

    if(i==j) diag[0] += adva;
    //~~not else if b/c could be overlapped
    if(i+j == 3)diag[1] += adva;
}
void print(){
    FOR(i,4) cout << g[i] << endl;
}
bool all_win_for_x(int p, int steps){
    if(steps == 16) return check(1);//all win or not win(draw) for y
    FOR(i, 4) FOR(j,4){
        if(g[i][j] == '.'){
            update(p, 0, i,j);
            if(check(p))
                { update(p, 1, i,j); return p==1;}
            else if(all_win_for_x(-p, steps+1)){
                if(p==1) { update(p,1,i,j); return 1;}
            }
            else if(p == -1)
                { update(p, 1, i,j); return 0;}
            update(p, 1, i,j);
        }
    }
    //y comes down here meaning it loses all, return 1
    //x comes down here meaning y wins somewhere, return 0
    return p == -1;
}
int main(){
    while(cin >> ch, ch != '$'){
        int steps = 0,adv;
        FOR(i,4) cin >> g[i];
        FOR(i,4) row[i] = col[i] = 0;
        diag[0] = diag[1] = 0;
        FOR(i,4) FOR(j,4) {
            if(g[i][j] == '.') continue;
            ++steps;
            update(g[i][j] == 'x'? 1: -1, 0, i,j);
        }
        r=c=-1;
        FOR(i,4) { FOR(j,4){
            if(g[i][j] == '.'){
                update(1,0,i,j);
                if(check(1) || all_win_for_x(-1,steps+1)) 
                { r= i,c = j; break;}
                update(1,1,i,j);
            }
        } if(r != -1 || c!= -1 ) break;}
        if(r != -1 &&  c != -1)
            printf("(%d,%d)\n",r,c);
        else printf("#####\n");
    } 
}