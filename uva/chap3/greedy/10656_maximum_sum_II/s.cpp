#include <iostream>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n, num,idx;
bool hasPos, has0;
int main(){
    while(scanf("%d",&n), n){
        idx = 0;
        FOR(i,n) {
            scanf("%d",&num);
            if(num){
                if(idx) printf(" ");
                printf("%d", num), ++idx;
            }
        }
        if(idx == 0) printf("0");
        printf("\n");
    }
}