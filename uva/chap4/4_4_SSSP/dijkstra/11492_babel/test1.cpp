#include <iostream>
using namespace std;


struct Cat{
    int age, hateful;
    Cat(int a, int h): age(a), hateful(h){}
};
int main(){
    Cat c(2,3);
    //illegal
    cout << c[0] << ' ' << c[1] << endl;
}