#include <iostream>
#include <math.h>
using namespace std;


//AC
#define PI 3.14159265
double a,b,v,A,t,dist;
int main(){
    while(scanf("%lf %lf %lf %lf %lf", &a,&b,&v,&A, &t), a+b+v+A+t){
        //dist = 1/2at^2=1/2vt(v=at, a=const)
        A = A/180*PI;
        dist = t*v/2;
        printf("%.0lf %.0lf\n", dist*cos(A)/a, dist*sin(A)/b);
    }
}