#include <iostream>
#include <math.h>
using namespace std;

//WA
uint32_t N, L, U, M, d, l;
void printBit(uint32_t k){
    if(k > 0){
        printBit(k/2);
        cout << (k%2);
    }
}

int main(){
    while(scanf("%d %d %d", &N, &L, &U)==3){
        d = log2(U);
        if(d < 32 && pow(2,d) < U) ++d;
        l = d == 32 ? (~0) : ((1 << d)-1);
        M = ~(((~0) - l) | N);
        // printBit(L), cout << endl;
        // printBit(M), cout << endl;
        // printBit(N), cout << endl;
        // printBit(U), cout << endl;
        // cout << L << ' ' << M << ' ' << U << ' ' << d << endl;
        // cout << endl;
        // if(M < L){
        for(int i = d-1; i >= 0 && M < L; --i){
            // if( (L & (1<<i)) && !(M &(1<<i)) ) M |= (1<<i);
            //largest bit in L must be present in M if M < L
            if( L & (1<<i) ) M |= (1<<i);
        }
        //adding bits with pos <= bits in U and in L
        //deleting bits > pos bits in U
        // }
        // if(M > U){
        for(int i = d-1; i >= 0 && M > U; --i){
            //wat smallest M so delete from highest first
            if( (M & (1<<i)) && !(U &(1<<i)) ) M &= (~(1<<i));
        }
        // }
        // printBit(M), cout << endl;
        cout << M << endl;
        // cout << endl;
    }
}

/*
Need to be revisited:
For case 
677743361 334357285 708439724
My output: 602792741
Expected output: 707650341
602792741 | 677743361 = 737012517
707650341 | 677743361 = 711846693
N:           101100000100100001110011011010
My M       : 100011111011011110001100100101
Expected M : 101010001011011110001100100101

and many other cases (from uva Debug)
I can get a smaller M by setting the smaller bits before 
and still make sure M is in range
unlike the greedy algorithm I learned online in s1.cpp

If you're here, let me know what you think!!!! 
My email is ctkhanhly@gmail.com

*/