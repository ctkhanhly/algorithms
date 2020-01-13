#include <iostream>
#include <string>
using namespace std;

//cetedel
/*
int countDegree(int start, int first, int second, int third){
    int res = 40*2 + (start - first + 40) % 40;//abs(first-start) --- from start to first ====> clockwise
    //int res = 40*2 + (40 - start + first);
    res += 40 + (40 + second - first) % 40; //from second to first, flipped from first to second since counter-clockwise
    res +=  (40 + second - third) % 40;
    // int res = 40*2 + 40 - abs(first -  start);
    // res += 40 + abs(second - first);
    // res += 40 - abs(third - second);
    return res*9;
}
*/

int countDegree(int start, int first, int second, int third){
    int res = 40*2 + (start - first + 40) % 40;
    res += 40 + (40 + second - first) % 40; 
    res +=  (40 + second - third) % 40;
    return res*9;
}

int main(){
    int start, first, second, third;
    //cin >> start >> first >> second >> third;
    //cout << countDegree(start, first, second, third) << endl;
    while(cin >> start >> first >> second >> third){
        if(start == 0 && first == 0 && second == 0 && third == 0){
            break;
        }
        cout << countDegree(start, first, second, third) << "\n";
    }
}