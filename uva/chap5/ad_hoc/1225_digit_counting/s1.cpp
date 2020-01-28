#include <iostream>
#include <string>
#include <math.h>
using namespace std;


#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int T,n,arr[10];
void cntDigits(int k,int sz){
    if(k < 10) 
        for(int i = 0; i <= k; ++i)
            ++arr[i];
    else if(k <100){
        // cout <<  k/10 << ' ' << k%10 << endl;
        arr[k/10] += k%10+1;
        for(int i = 1; i < k/10; ++i)
            arr[i] += 10;
        for(int i = 0; i < 10; ++i)
            arr[i] += k/10;
        for(int i = 1; i <= k%10; ++i) 
            ++arr[i];
    }
    else {
        string num = to_string(k);
        // cout << num.size() << endl;
        int numInt = stoi(num.substr(1));
        arr[num[0]-'0']+= numInt+1;
        // arr[0] += num.size()-1;//ahhh 0 case
        //105, 1005,1025=> all these padded 0s in between
        arr[0] += numInt;
        cntDigits(numInt);
        cntDigits(pow(10,num.size()-1)-1);
    }
}
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scanf("%d", &n);
        FOR(i,10) arr[i] = 0;
        cntDigits(n);
        FOR(i,10) { 
            if(i < 9) printf(" "); 
            else printf("\n"); 
            printf("%d", arr[i]);
        }
    }
}