#include <iostream>
#include <string>
#include <vector>
using namespace std;


//AC
typedef vector<int> vi;
#define pb push_back
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int d, lastD, dist, lCap, cap;
string s,event;
double tank, currTank;
vi leaks;
int main(){
    while(cin >> d){
        cin >> event;  
        // tank = 0;
        //read
        if(event == "Fuel") {
            cin >> s, cin >> cap;
            if(d == 0 && cap == 0) break;
            if(d==0) lastD = d = currTank = tank = 0, leaks.clear(), lCap = cap;
        }
        else if(event == "Gas")  cin >> s;
        
        //process
        dist = d - lastD;
        currTank += dist/100.0 * lCap;
        FOR(i,leaks.size()) currTank += (d-leaks[i]);
        tank = max(tank, currTank);
        if(event == "Fuel"){
            if(d == 0) continue;
            lCap = cap;
        }
        else if(event == "Gas"){
            currTank = 0;
        }
        else if(event == "Leak") leaks.pb(d);
        else if(event == "Mechanic")  leaks.clear();
        else printf("%.3lf\n", tank);
        // cout << d << ' ' << dist << ' ' << tank << ' ' << cap << endl;
        FOR(i, leaks.size()) leaks[i] = d;
        lastD = d;
    }
}