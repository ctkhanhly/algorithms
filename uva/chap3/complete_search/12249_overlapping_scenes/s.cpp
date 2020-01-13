#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
int T,n, res,cost;
string sample;
bool matched;
string s;
vector<string> scenes;
//Trie
//first sort them all
int main(){
    scanf("%d", &T);
    FOR(z,T){
        scenes.clear();
        scanf("%d", &n);
        res = 0;
        sample="";
        FOR(p,n) cin >> s, scenes.pb(s), res+= s.size(), sample +=s;
        if(n>0){
            sort(scenes.begin(), scenes.end());
            do{
                cost = scenes[0].size();
                sample = scenes[0];
                FOR(i, scenes.size()-1){
                    matched = false;
                    for(int sz = scenes[i+1].size(); sz >= 1 ; --sz){
                        if(sz <= sample.size() && sample.substr(sample.size()-sz) == scenes[i+1].substr(0, sz)){
                            cost += scenes[i+1].size() - sz;
                            sample += scenes[i+1].substr(sz);
                            matched = true;
                            break;
                        }
                    }
                    if(!matched) cost += scenes[i+1].size(), sample += scenes[i+1];
                }
                res = min(res, cost);
            }while(next_permutation(scenes.begin(), scenes.end()));
        }
        printf("Case %d: %d\n", z+1, res);
        
    }
}
//10 possible cuts=>100max slices, 6 strings
//6! ordering