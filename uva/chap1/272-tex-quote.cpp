#include <iostream>
#include <string>
// #include <cstdio>
using namespace std;

//https://en.cppreference.com/w/cpp/language/operator_alternative
//built-in for c++
int main(){
    //#include <cstdio>
    // int a = 1, b = 2;
    // cout << a and b;
    // cout << endl;
    int count = 0;
    //cin.peek()
    while(!cin.eof()){
        if(count != 0){
            cout << "\n";
        }
        string s;
        getline(cin, s);
        string res;
        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == '\"'){
                ++count;
                if(count % 2 == 0){
                    res.append("\'\'");
                }
                else{
                    res.append("``");
                }
            }
            else{
                res.push_back(s[i]);
            }
        }
        cout << res;
        //cout << endl;
        //cout << s << endl;

    }
}