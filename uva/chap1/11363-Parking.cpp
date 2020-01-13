#include <iostream>
#include <cstdio>
#include <algorithm>
using  namespace std;

int main(){
    int T, n, x;
    cin >> T;
    while(T > 0){
        cin >> n;
        // 0 ≤ xi ≤ 99
        int biggest = 0, smallest = 99;
        while(n > 0){
            cin >> x;
           if(x > biggest) biggest = x;
           if(x < smallest) smallest = x;
            --n;
        }
        cout << (biggest - smallest)*2 << "\n";
        --T;
        //if(T != 0) cout <<  '\n';
    }
}

/*
//  error: variable-sized object may not be initialized
//         int stores[numStores] = {};
//no newline
printf("a");
    printf("b");
int T, n, i;
cin >> T;
while(T > 0){
    cin >> n;
    int stores[n];
    int numOfStores = n;
    while(n > 0){
        cin >> i;
        stores[numOfStores - n] = i;
        --n;
    }
    sort(stores, stores + numOfStores);
    //cout  << stores[numOfStores - 1] << ' ' << stores[0] << endl;
    cout << (stores[numOfStores - 1] - stores[0])*2;
    --T;
    if(T != 0) cout <<  '\n';
}
*/