#include <iostream>
#include <string>
#include <map>
#define forA(i,n) for(size_t i = 0; i < size_t(n); ++i)
using namespace std;

int main(){
	size_t n, g, n_g, e,ind, T = 1;//g = gifts, e = for each person
	string name;
	while(cin >> n){
		string names[n];
		map<string, int> net;
        ind = 0;
		while(n--){
			cin >> name;
			names[ind++] = name;
            net[name] = 0;
		}
		n = ind;
		while(n--){
			cin >> name >> g;
			cin >> n_g;
            //if given to no one =>  dont reduce g 
            //net[name] -= g;
			if(n_g){
				e = g / n_g;
                net[name] -= g;
				net[name] += (g % n_g);
			}
			while(n_g--){
				cin >> name;
				net[name] += e;
			}
		}
        // "The output for each group should be separated from other 
        // groups by a blank line."
        if (T++ > 1)
            cout << endl;

        //https://github.com/ajahuang/UVa/blob/master/UVa%20119%20-%20Greedy%20Gift%20Givers.cpp

		n = ind;
		forA(i, n) cout << names[i] << ' ' << net[names[i]] << '\n';
	}
}	

//http://www.cplusplus.com/reference/algorithm/find/

//another idea: stores ordered array of names and then store net worth in a map

