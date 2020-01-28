#include <iostream>
#include <math.h>
using namespace std;

//AC
int n,X,x,y;
int g[100][100];
void printBoard(int num){
    int curr = 0;
    for(int i = 0; i <= sqrt(X)+1; ++i)
        for(int j = 0; j <= sqrt(X)+1; ++j)
            g[i][j] = 0;
    for(int sz = 1; sz <= sqrt(num)+1; ++sz){
        if(sz &1){
            for(int i = 0; i < sz && curr < num; ++i){
                g[sz-1][i] = ++curr;
            }
            for(int j = sz-2; j >=0 && curr < num; --j) 
                g[j][sz-1] = ++curr;
        }
        else{
            for(int i = 0; i < sz && curr < num; ++i){
                g[i][sz-1] = ++curr;
            }
            for(int j = sz-2; j >=0 && curr < num; --j) 
                g[sz-1][j] = ++curr;
        }
        if(curr == num) break;
    }
    for(int i = 0; i <= sqrt(X)+1; ++i){
        for(int j = 0; j <= sqrt(X)+1; ++j)
            cout << g[i][j] << ' ';
        cout << endl;
    }
        
}
int main(){
    while(scanf("%d", &X), X){
        n = sqrt(X);
        // if(n+1 <= 100) printBoard(X);
        X -= n*n;
        if(X == 0) x = n, y = 1;
        else if(X <= n+1) x = n+1, y = X;
        else x = n+1-(X - n-1), y = n+1;
        if(n&1) swap(x,y);
       
        printf("%d %d\n", x, y);
    }
}