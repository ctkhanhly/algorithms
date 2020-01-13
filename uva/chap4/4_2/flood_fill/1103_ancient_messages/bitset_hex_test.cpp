#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
    int hNum;
    cin >> hex >> hNum;
    cout << hNum << endl;
    cout << hex << hNum << endl;
    cout << to_string(hNum) << endl;
    // bitset<16> b1(to_string(hNum));//invalid
    bitset<16> b2(hNum);
    // cout << b1 << endl;
    cout << b2 << endl;
}