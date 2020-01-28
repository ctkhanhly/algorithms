#include <iostream>
#include <math.h>
using namespace std;


//AC
#define PI 3.14159265
#define fi first
#define se second
const int N = 46500;
typedef pair<double,double> dd;
int n, m,order;
double x,y,res;
const double side = 1;
dd p1,p2;

//square numbers are sum of odd numbers
dd toCoord(int num){
    order = sqrt(num);
    //math~~~~~~
    y = side*cos(PI/6)*(order+2./3*((num-order)&1? 1./2 : 1));
    // cout << order << ' ' << num << endl;
    x = (num - (order*order+order))/2.;//(2*(order+1)+1)/2+1
    return {x,y};
}
int main(){
    while(scanf("%d %d", &n, &m)==2){
        p1 = toCoord(n), p2 = toCoord(m);
        // printf("(%lf,%lf) (%lf, %lf)\n", p1.fi, p1.se, p2.fi, p2.se);
        x = p1.fi - p2.fi, y = p1.se - p2.se;
        res = sqrt(x*x + y*y);
        printf("%.3lf\n", res);
    }
}