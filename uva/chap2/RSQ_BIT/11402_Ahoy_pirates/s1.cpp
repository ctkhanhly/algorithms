#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int C, n, T, M, Q,a,b,p;
char A;

const int N = 1024000+1;
int st[4*N];//ignore 0
char piece[50];
int pirates[N];


void buildST(int l, int r, int k){
    if(l == r) { st[k] = pirates[l];}
    else{
        int m = (l+r)/2;
        buildST(l, m, 2*k+1);
        buildST(m+1,r, 2*k+2);
        st[k] = st[2*k+1] + st[2*k+2];
        // cout << l << ' ' << r << ' ' << st[k] << endl;
    }
}
//cannot be correct
//they are all messed up
//you just stop at random node and how can you make sure you walk through all your tree to update
//must deal using lazy prop by saving which node needs to be modified later
void propagate(int i, int j, int l, int r, int k){
    if(i > r || j < l) st[k] = st[2*k+1] + st[2*k+2];
    else if(l == r){
        // cout << st[k] << endl;
        if(A == 'I') st[k] = !st[k];
        else if(A == 'F') st[k] = 1;
        else if(A == 'E') st[k] = 0;
    }
    else{
        int m = (l+r)/2;
        propagate(i,j,l,m, 2*k+1);
        propagate(i,j,m+1, r, 2*k+2);
        if(i >= l && j <= r){
            if(A == 'I') st[k] = (r-l+1) - st[k];
            else if(A == 'F') st[k] = (r-l+1);
            else if(A == 'E') st[k] = 0;
        }
        st[k] = st[2*k+1] + st[2*k+2];
    }
    
}
void update(int i, int j, int l, int r, int k){
    if(i > r || j < l) return;
    //as soon as you see a match, stop
    if(i >= l && j <= r) propagate(i,j, l,r,k);
    else{
        int m = (l+r)/2;
        update(i,j, l, m, 2*k+1);
        update(i,j, m+1,r, 2*k+2);
        st[k] = st[2*k+1] + st[2*k+2];
    }
}
int answerGod(int i, int j, int l, int r, int k){
    if(i > r || j < l) return 0;
    if(i >= l && j <= r)  return st[k];
    int m = (l+r)/2;
    return answerGod(i,j, l,m,2*k+1) + answerGod(i,j, m+1, r, 2*k+2);
}

int main(){
    cin >> C;
    FOR(z, C){
        cin >> M;
        n = 0;
        FOR(p, M){
            cin >> T >> piece;
            FOR(i,T)
                for(int j  = 0;piece[j]; ++j, ++n) pirates[n] = piece[j]-'0';
        }
        pirates[n] = '\0';
        FOR(i,n) cout << pirates[i];
        cout << endl;
        FOR(i, 4*n) st[i] = 0;
        buildST(0,n-1,0);
        cin >> Q;
        printf("Case %d:\n", z+1);
        p = 1;
        FOR(q, Q){
            cin >> A >> a >> b;
            if(A == 'S') printf("Q%d: %d\n", p, answerGod(a,b,0,n-1,0) ),++p;
            else update(a,b,0,n-1,0);
        }
    }
}