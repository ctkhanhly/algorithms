#include <iostream>
#include <unordered_map>
#include <string>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define fi first
#define se second
int N, K, M;
const int MAXK = 101;
unordered_map<char,ii> paySys;
char c;
string line;
ll cents;
double tot;//max = 15*10^8 chars
int main(){
    cin >> N;
    FOR(z, N){
        cin >> K;
        paySys.clear();
        FOR(p, K){
            cin >> c >> cents;
            paySys[c] = {cents,0};
        }
        cin >> M;
        cin.ignore();
        FOR(p, M){
            getline(cin, line);
            for(char c: line) if(paySys.count(c)) ++paySys[c].se;
        }
        tot = 0;
        for(auto it = paySys.begin(); it != paySys.end(); ++it) tot += it->se.fi *it->se.se;
        //cout << it->se.fi << ' ' << it->se.se << endl;
        // cout << tot << endl;
        printf("%.02f$\n", tot/100);
    }
}