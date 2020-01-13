#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdio.h>
using namespace std;

//I changed include statements to <bits/stdc++.h>
//since uva uses c++11 which does not have gcd()

#define FOR(i,n) for(int i = 0;i < (int)n; ++i)
#define fi first
#define se second
typedef pair<int,int> ii;
const int N = 10;
int f,r,a,b,n, com;
int front[N], rear[N];
ii driveRatios[N*N];
class Comp{
public:
    bool operator()(const ii& p1, const ii& p2) const {
        return p1.fi * p2.se  < p1.se * p2.fi;
    }
};
ostream& operator<<(ostream& os, const ii& p){ os << "(" << p.fi << ',' << p.se << ')'; return os; }
int main(){
    while(cin>> f, f){
        scanf("%d",&r);
        FOR(z,f) scanf("%d",&front[z]);
        FOR(z,r) scanf("%d", &rear[z]);
        // sort(front, front+f);
        // sort(rear, rear+r);
        a = b = 1;
        n= 0;
        FOR(i, f){
            FOR(j, r){
                driveRatios[n++] = {rear[j], front[i]};
            }
        }
        sort(driveRatios, driveRatios+n, Comp());
        // FOR(i,n) cout << driveRatios[i] << ' ';
        // cout << endl;
        FOR(i,n-1){
            if(driveRatios[i+1].fi * driveRatios[i].se * b > a * driveRatios[i+1].se * driveRatios[i].fi){
                a = driveRatios[i+1].fi * driveRatios[i].se, b = driveRatios[i+1].se * driveRatios[i].fi;
                com = gcd(a,b);
                a /= com, b/= com;
                // cout << a << ' ' << b << endl;
            }
        }
        printf("%.2lf", (double)a/b);
    }
    
}