#include <iostream>
#include <string>
using namespace std;

int main(){
    int count = 0;
    // while(cin.peek() != cin.eof()){
     while(!cin.eof()){
        if(count != 0){
            cout << "\n";
        }
        string s;
        getline(cin,s);
        cout << s;
        ++count;
    }
}