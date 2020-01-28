#include <iostream>
#include <string>
using namespace std;


//AC
const int N = 5842;
#define FOR(i,n) for(int i = 1; i < (int)n; ++i)
int n, hum[N+5],idx2,idx3,idx5,idx7,idx;
string suff[] = {"st", "nd", "rd", "th"};
int main(){
    idx2=idx3=idx5=idx7 = 1;
    hum[1] = 1;
    for(int i = 2; i <= N; ++i){
        hum[i] = min(min(hum[idx2]*2,hum[idx3]*3), min(hum[idx5]*5,hum[idx7]*7));
        if(hum[i] == hum[idx2]*2) ++idx2;
        if(hum[i] == hum[idx3]*3) ++idx3;
        if(hum[i] == hum[idx5]*5) ++idx5;
        if(hum[i] == hum[idx7]*7) ++idx7;
    }
    while(scanf("%d", &n), n){
        if(10< n%100 && n%100 < 20 ) idx = 4;
        else idx = min(4, n%10);
        idx = idx ? idx-1 : 3;
        printf("The %d%s humble number is %d.\n", n, suff[idx].c_str(), hum[n]);
    }
}