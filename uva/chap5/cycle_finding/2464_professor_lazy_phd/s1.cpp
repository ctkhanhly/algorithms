#include <iostream>
using namespace std;


//AC
typedef long long ll;
int a,b,res;
ll n;
int main(){
    while(scanf("%d %d %lld", &a,&b,&n), a+b+n){
        switch(n%5){
            case 0: 
                res = a; break;
            case 1:
                res = b; break;
            case 2: 
                res = (b+1)/a; break;
            case 3: 
                res = (a+b+1)/(a*b); break;
            case 4:
                res = (a+1)/b; break;
        }
        printf("%d\n", res);
    }
}

/*
3: (1+(b+1)/a )/b = (a+b+1)/ab
4: ((a+b+1)/ab +1)/((b+1)/a) = .... = (a+1)/b
5: (1+(a+1)/b)/((a+b+1)/ab) = ... = a!!!
*/