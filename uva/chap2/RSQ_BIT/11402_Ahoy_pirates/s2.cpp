#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int C, n, T, M, Q,a,b,p;
char A;
const int N = 1024000+1;
int st[4*N];
char lazy[4*N];//ignore 0
char piece[50];
int pirates[N];


void buildST(int l, int r, int k){
    if(l == r) { st[k] = pirates[l], lazy[k] = 'U';}
    else{
        int m = (l+r)/2;
        buildST(l, m, 2*k+1);
        buildST(m+1,r, 2*k+2);
        st[k] = st[2*k+1] + st[2*k+2];
        lazy[k] = 'U';
    }
}
void updateSpell(int k, char spell){
    if(spell == 'I'){
        switch(lazy[k]){
            case 'F': lazy[k] = 'E'; break;
            case 'E': lazy[k] = 'F'; break;
            case 'I': lazy[k] = 'U'; break;
            case 'U': lazy[k] = 'I'; break;
            default: return;
        }
    }
    else lazy[k] = spell;
}
//cannot be correct
void propagate(int l, int r, int k){
    if(lazy[k] == 'U') return;
    if(lazy[k] == 'I') st[k] = (r-l+1)-st[k];
    else if(lazy[k] == 'F') st[k] = r-l+1;
    else if(lazy[k] == 'E') st[k] = 0;
    //U no change
    updateSpell(2*k+1, lazy[k]);
    updateSpell(2*k+2, lazy[k]);
    lazy[k] = 'U';//done
}

void update(int i, int j, int l, int r, int k){
    if(l >= i && r <= j) updateSpell(k,A);//deal with flip
    propagate(l,r,k);//perform change
    //change the spell from all nodes
    //=> changed from last update
    //doesnt neccessarily just change i,j interval
    if(r < i || l > j || (l >= i && r <= j)) return;
    int m = (l+r)/2;
    update(i,j, l, m, 2*k+1);
    update(i,j, m+1,r, 2*k+2);
    st[k] = st[2*k+1] + st[2*k+2];

}
int answerGod(int i, int j, int l, int r, int k){
    propagate(l,r,k);
    if(r < i || l > j) return 0;
    if(l >= i && r <= j)  return st[k];
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
        // FOR(i,n) cout << pirates[i];
        // cout << endl;
        // cout << n << endl;
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