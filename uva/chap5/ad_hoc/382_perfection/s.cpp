#include <iostream>
#include <math.h>
using namespace std;


//AC
int sum, num;
int main(){
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &num), num){
        sum = 0;
        for(int i = 1; i <= sqrt(num); ++i){
            if(num%i == 0 && num != 1) {
                sum += i;
                if(i*i == num || i==1) continue;
                sum += num/i;
            }
        }
        // cout << sum << endl;
        printf("%5d  ", num);
        if(num == sum) printf("PERFECT\n");
        else if(sum < num) printf("DEFICIENT\n");
        else printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
}