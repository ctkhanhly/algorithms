#include <iostream>
#include <string>
#include <vector>
using namespace std;


//AC, probably not very good code since I ran through all possible cases
typedef vector<string> vs;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
int sz,z;
string mom, dad, child;
vs res;
void addParent(const string& parent){
    if(parent.size() == child.size()) {
        if(parent[0] == child[0]){//A,B, O, AB
            res.pb("A+"), res.pb("B+");
            if(parent.size() == 2) res.pb("O+");
            if(child[0] != 'O') res.pb("AB+");
        }
        else{//A-O, B-O, A-B, O-B, O-A, B-A
            // if(parent[0] == 'O') res.pb(child), res.back()[res.back().size()-1] = '+';
            if(child[0] == 'O') res.pb("A+"), res.pb("B+"), res.pb("O+");
            else res.pb(child), res.back()[res.back().size()-1] = '+';
            if(child[0] != 'O') res.pb("AB+");
        }
    }
    else{
        if(parent.size() == 3){//child A,B, O
            if(child[0] == 'O') res.pb("O+");
            else res.pb("A+"), res.pb("B+"), res.pb("O+"), res.pb("AB+");
        }
        else{//child = AB, parent not A,B, or O
            res.pb("AB+");
            // if(parent[0] == 'O') 
            if(parent[0] == 'A') res.pb("B+");
            else res.pb("A+");
        }
    }
}
void addRh(char sign){
    sz = res.size();
    FOR(i, sz){
        res.pb(res[i]);
        res.back()[res.back().size()-1] = sign;
    }
}
int main(){
    z = 1;
    while(cin >> mom >> dad >> child && !(mom == "E" && dad == "N" && child == "D")){
        res.clear();
        // cout << mom << ' ' << dad << ' ' << child << endl;
        cout << "Case " << z << ": ";
        if(mom == "?" ) {
            if(!((dad.size() == 3 && child[0] == 'O')|| (dad[0] == 'O' && child.size() == 3))){
                addParent(dad);
                if(!(dad.back() == '-' && child.back() == '+')) addRh('-');
            }
            if(! res.empty()){
                if(res.size() > 1) cout << '{';
                FOR(i, res.size()) { cout << res[i]; if(i+1 < res.size()) cout << ", ";}
                if(res.size() > 1) cout << '}';
            }
            else cout << "IMPOSSIBLE";
            cout << ' ' << dad << ' ' << child << endl;
        }
        else if(dad == "?") {
            if(!((mom.size() == 3 && child[0] == 'O')|| (mom[0] == 'O' && child.size() == 3))){
                addParent(mom);
                if(!(mom.back() == '-' && child.back() == '+')) addRh('-');
            }
                
            cout << mom << ' ';
            if(!res.empty()){
                if(res.size() > 1) cout << '{';
                FOR(i, res.size()) { cout << res[i]; if(i+1 < res.size()) cout << ", ";}
                if(res.size() > 1) cout << '}';
            }
            else cout << "IMPOSSIBLE";
            cout << ' ' << child << endl;
        }
        else {
            if(mom.size() == 3 && dad.size() == 3) res.pb("A-"), res.pb("B-"), res.pb("AB-");
            else{
                if(mom[0] == 'A' || dad[0] == 'A') res.pb("A-");
                if(mom[0] == 'B' || dad[0] == 'B'||mom.size() ==3 || dad.size() == 3) res.pb("B-");
                if(mom.size() != 3 && dad.size() != 3) res.pb("O-");
                if( (mom[0] != dad[0] && mom[0] != 'O' && dad[0] != 'O') ||
                    (mom.size() == 3 && dad.size() == 3) || (mom.size() == 3 && dad[0] != 'O')||
                    (dad.size() == 3 && mom[0] != 'O')) res.pb("AB-");
            }
            if(!(mom.back()== '-' && dad.back() == '-')) addRh('+');
            cout << mom << ' ' << dad << ' ';
            if(res.size() > 1) cout << '{';
            FOR(i, res.size()) { cout << res[i]; if(i+1 < res.size()) cout << ", ";}
            if(res.size() > 1) cout << '}';
            cout << endl;
        }
        ++z;
    }
    //OB, AO: 37,40
    //AB: 66
}