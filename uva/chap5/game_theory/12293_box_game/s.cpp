#include <iostream>
using namespace std;

//AC
int n;
int main(){
    while(scanf("%d", &n),n){
        if((n+1) == ((n+1)&(-n-1))) printf("Bob\n");
        else printf("Alice\n");
    }
}

/*
n is odd:
case 1: make even the bigger pile => you lose
case 2: make even the smaller pile
opponent will redistribute odd so that even is smaller pile
n = 2i+1=> odd at least i+1 except for n=3=> loses
1 2 3 4 5 6
1 1 1 1 1 1
Alice can only take bits <= 5
Bob can restore by taking opposite bits to Alice <=5 +1
=> Alice will face with set bits 1-5
Alice took at least 1 stone => Bob takes <= summation 2^i, i <=5 -1 = 2^6-2 
=> Bob takes a smaller chunk than 2^6-1
*/