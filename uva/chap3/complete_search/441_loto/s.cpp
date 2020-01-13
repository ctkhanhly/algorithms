#include <iostream>
#include <stdio.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 13;
int arr[N],k,z;
int main(){
    z = 0;
    while(cin >> k,k){
        if(z) cout << endl;
        FOR(i, k) cin >> arr[i];
        FOR(a,k-5)
            for(int b = a+1; b < k-4; ++b)
                for(int c = b+1; c < k-3; ++c)
                    for(int d = c+1; d < k-2; ++d)
                        for(int e = d+1; e < k-1; ++e)
                            for(int f = e+1; f < k; ++f)
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
        ++z;
    }
}