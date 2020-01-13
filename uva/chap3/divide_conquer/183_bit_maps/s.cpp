#include <iostream>
#include <iomanip>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 200;
char type;
int n,m, g[N][N],idx,r,c,p;
string res, D,s;
void fill(int r1, int c1, int r2, int c2, int num){
    for(int i = r1; i <= r2; ++i){
        for(int j = c1; j <= c2; ++j) g[i][j] = num;
    }
}
void BToD(int r1, int c1, int r2, int c2){
    if(r1> r2 || c1 > c2) return;
    bool divide = false;
    int num = g[r1][c1];
    for(int i = r1; i <= r2; ++i){
        for(int j = c1; j <= c2; ++j) if(g[i][j] != num){ divide = true; break;}
        if(divide) break;
    }
    if(p && (p %50 ==0)) cout << endl;
    ++p;
    if(divide){
        cout << 'D';
        int midR = (r1+r2)/2;
        int midC = (c1+c2)/2;
        BToD(r1,c1, midR, midC);
        BToD(r1, midC+1, midR, c2);
        BToD(midR+1, c1, r2, midC);
        BToD(midR+1, midC+1, r2,c2);
    }
    else{
        cout << num;
    }
}
int DToB(int r1, int c1, int r2, int c2, int i){
    if(i >= D.size()) return i;
    if(r1> r2 || c1 > c2) return i-1;
   
    if(D[i] == 'D'){
        int midR = (r1+r2)/2;
        int midC = (c1+c2)/2;
        
        int j = DToB(r1,c1, midR, midC,i+1);
        j = DToB(r1, midC+1, midR, c2,j+1);
        j = DToB(midR+1, c1, r2, midC,j+1);
        j = DToB(midR+1, midC+1, r2,c2,j+1);
        return j;
    }
    else {
        fill(r1,c1,r2,c2, D[i]-'0');
        return i;
    }
}
void printB(){
    p = 0;
    FOR(i,n) FOR(j,m) { if(p && p%50==0) cout << endl; ++p; printf("%d", g[i][j]);}
    printf("\n");
}
int main(){
    while(cin >> type && type != '#'){
        cin >> n >> m;
        cout << (type == 'B'? 'D': 'B') << right << setw(4) << n << right << setw(4) << m << endl;
        cin.ignore();
        if(type == 'B'){
            s.clear();
            while( s.size() < n*m){
                getline(cin,D);
                s+=D;
            }
            p = 0;
            idx = 0;
            FOR(i,n) FOR(j,m) g[i][j] = s[idx++]-'0';
            res.clear();
            BToD(0,0,n-1,m-1);
            cout << endl;
        }
        else{
            getline(cin,D);
            DToB(0,0,n-1,m-1,0);
            printB();
        }
    }
}