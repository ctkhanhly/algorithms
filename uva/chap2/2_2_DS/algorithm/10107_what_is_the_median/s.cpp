#include <iostream>
#include <algorithm>
using namespace std;

//AC
const int N = 10000;
int X, n, arr[N],med;
int main(){
    n= 0;
    while(cin>> X){
        arr[n] = X;
        ++n;
        // if(n&1) nth_element(arr, arr+(n+1)/2, arr+n), med = arr[n/2];
        // else{
        //     nth_element(arr, arr+ n/2, arr+n);
        //     med = arr[n/2-1];
        //     nth_element(arr, arr+ n/2+1, arr+n);
        //     med += arr[n/2];
        //     med/=2;
        // }
        if(n&1) nth_element(arr, arr+n/2, arr+n), med = arr[n/2];
        else{
            nth_element(arr, arr+ n/2-1, arr+n);
            med = arr[n/2-1];
            nth_element(arr, arr+ n/2, arr+n);
            med += arr[n/2];
            med/=2;
        }
        cout << med << endl;
    }
}