#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 8;
const int INF = 8*150*2+100;
int n, x[N], y[N], p[N],finalP[N], z, xc,yc,s,e;
double dist[N][N], res, cost;
int main(){
    z = 1;
    while(scanf("%d", &n),n){
        FOR(i,n){
            p[i] = i;
            dist[i][i] = 0;
            scanf("%d %d", &x[i], &y[i]);
            FOR(j,i){
                xc = x[i]-x[j], yc = y[i]-y[j];
                dist[i][j] = dist[j][i] = sqrt(xc*xc + yc*yc);
            }
        }
        res = INF;
        do{
            cost = 0;
            FOR(i,n-1) cost += dist[ p[i] ][ p[i+1] ];
            if(cost < res){
                res = cost;
                copy(p, p+n, finalP);
            }
        }while(next_permutation(p, p+n));
        printf("**********************************************************\n");
        printf("Network #%d\n",z);
        FOR(i, n-1) {
            s = finalP[i], e = finalP[i+1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
                x[s], y[s], x[ e ], y[ e ], dist[s][ e ]+16);
        }
        printf("Number of feet of cable required is %.2lf.\n", res+16*(n-1));
        ++z;
    }
}