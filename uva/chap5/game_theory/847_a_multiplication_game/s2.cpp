#include <iostream>
#include <fstream>
using namespace std;

//AC
unsigned int p,n;
bool res;
int main(){
    // ofstream ofs;
    // ofs.open("in.txt", std::ofstream::out | std::ofstream::app);
    // // cout << ofs.is_open() << endl;
    // for(int i = 163; i <= 3000; ++i)
    //     ofs << i << endl;
    // ofs.close();
    while(scanf("%u", &n)==1){
        res = 0;
        p = 1;
        while(p < n) p *= res ? 2 : 9, res ^= 1;
        if(res) printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }
}