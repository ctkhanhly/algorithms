#include <iostream>
using namespace std;


//AC
double ans,cows, cars, shows;
int main(){
    while(scanf("%lf %lf %lf", &cows, &cars, &shows)==3){
        ans = cows/(cows+cars)*cars/(cars+cows-shows-1)
            + cars/(cows+cars)*(cars-1)/(cars+cows-shows-1);
        printf("%.5lf\n", ans);
    }
}