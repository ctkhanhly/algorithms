#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

const int MAX_N = 1024000+1;
#define FOR(i,n) for(int i =0; i < (int)n; ++i)
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

//Buccaneer = 1
//Barbary = 0

//TLE
class BIT{
    vc ft;
    string pirates;
    int n;
    int LSOne(int k) { return k & (-k);}
    void build(){ FOR(i,n) update(i, pirates[i]-'0'); }
    int rsq(int k) { int sum = 0; for(int i = k+1; i > 0; i -= LSOne(i)) sum+=ft[i]; return sum;}
    void update(int k, int diff){ for(int i = k+1; i < n; i+= LSOne(i)) ft[i]+= diff;}
public:
    BIT(char* _pirates, int _n): pirates(_pirates), n(_n+1){
        ft = vc(n,0);
        build();
    }
    int rsq(int a, int b) {return rsq(b) - rsq(a-1);}
    void F(int a, int b){
        //1 million logn
        // for(int i = a; i <=b; ++i){
        //     int next = i + LSOne(i);
        //     if(pirates[i] == '0') update(i,1);
        //     pirates[i] = '1';
        // }
        // update()
    }
    void E(int a,int b){
        for(int i = a; i <=b; ++i){
            if(pirates[i] == '1') update(i, -1);
            pirates[i] = '0';
        }
    }
    void I(int a, int b){
        for(int i = a; i <=b; ++i){
            if(pirates[i] == '1') update(i, -1), pirates[i] = '0';
            else update(i, 1), pirates[i] = '0';
        }
    }
};
int main(){
    int M, T, t, N, Q, a, b;
    char q;
    string s;
    char pirates[MAX_N];
    cin >> t;
    FOR(z,t){
        cin >> M;
        int i = 0;
        FOR(x,M){
            cin >> T >> s;
            FOR(y, T){
                copy(s.begin(), s.end(), pirates+i);
                i+= s.size();
            }
        }
        pirates[i] = '\0';
        BIT bit(pirates,i);
        cin >> Q;
        if(z) cout << endl;
        cout << "Case " << z+1 << ":\n";
        int qth = 1;
        FOR(x, Q){
            cin >> q >>a >> b;
            if(q == 'F') bit.F(a,b);
            else if(q == 'E') bit.E(a,b);
            else if( q == 'I') bit.I(a,b);
            else{
                int ans = bit.rsq(a,b);
                if(qth>1) cout <<endl;
                printf("Q%d: %d", qth++, ans);
            }
        }
    }
}
/*
F a b, means, mutate the pirates from index a to b to Buccaneer Pirates.
E a b, means, mutate the pirates from index a to b to Barbary Pirates.
I a b, means, mutate the pirates from index a to b to inverse pirates.
S a b, means, “God’s query” God is asking a question: “Tell me, how many Buccaneer pirates are
there from index a to b?”
*/