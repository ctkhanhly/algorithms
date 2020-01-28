#include <iostream>
// #include <math.h>
using namespace std;


//AC
#define EPS 1e-9
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
double arr[1000],sum, res,avg, up, down;
int n;  
double round(double a){
    return (int)((a*100.))/100.;//ok within 0.1=> doesnt need 0.5
}
int main(){
    while(scanf("%d",  &n), n){
        sum = 0;
        FOR(i,n) scanf("%lf", arr+i), sum += arr[i];
        avg = sum/n;
        res = 0;
        // avg = (int)(avg*100)/100.;
        up = down = 0;
        // cout << avg << endl;
        FOR(i,n) {
            if(arr[i] > avg) down += round(arr[i]-avg);
            else up += round(avg-arr[i]);
        }
        res = max(up,down);
        printf("$%.2lf\n", res);
    }
}