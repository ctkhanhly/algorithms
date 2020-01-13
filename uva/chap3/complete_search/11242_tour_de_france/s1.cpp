#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10;
int f,r, front[N], rear[N],t,n;
double driveRat[N*N], res;
// bool compRat(double a, double b) { return a < b;}
int main(){
    while(cin >> f, f){
        cin >> r;
        FOR(i, f) cin >> front[i];
        n = 0;
        FOR(i, r){
            cin >> rear[i];
            FOR(j, f) driveRat[n++] = (double)rear[i]/front[j];
        }
        sort(driveRat, driveRat+n);
        res = 1;
        FOR(i,n-1) res = max(res, driveRat[i+1]/driveRat[i]);
        printf("%.2lf\n", res);
    }
}