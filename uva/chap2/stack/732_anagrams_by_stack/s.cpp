#include <iostream>
#include <string>
#include <stack>
using namespace std;


//AC
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
//until you see a first matching character
string source, target,stseq, res;
stack<char> builder;
int n;
void backtrack(int i, int k){
    if(k == n){
        if(stseq == target && i == n && builder.empty()) {
            FOR(j,res.size()) { 
                if(j) cout << ' '; 
                cout << res[j];
            }
            puts("");
        }
    }
    else{
        if(i < n){
            res += 'i';
            builder.push(source[i]);
            backtrack(i+1,k);
            builder.pop();
            res.pop_back();
        }
        if(!builder.empty() && builder.top() == target[k]){
            res += 'o';
            stseq.pb(builder.top());
            builder.pop();
            backtrack(i,k+1);
            builder.push(stseq.back());
            stseq.pop_back();
            res.pop_back();
        }
        //otherwise, this sequence does not work, just backtrack!
    }
}
int main(){
    while(cin >> source >> target){
        n = source.size();
        // builder = stack<char>();
        cout << "[\n";
        backtrack(0,0);
        cout << "]\n";
    }
}