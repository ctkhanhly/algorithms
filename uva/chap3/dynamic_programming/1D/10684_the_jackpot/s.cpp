#include <iostream>
#include <algorithm>
using namespace std;

//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 10000;
int n, currSum, mxSum, num;
int main(){
    while(scanf("%d", &n) , n){
        currSum = 0;
        mxSum = 0;
        FOR(i, n) {
            scanf("%d", &num);
            currSum = max(currSum+num, num);
            mxSum = max(mxSum, currSum);
        }
        if(mxSum == 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", mxSum);
    }
}