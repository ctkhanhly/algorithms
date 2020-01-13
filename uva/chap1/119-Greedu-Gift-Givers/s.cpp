#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define forA(i,n) for(size_t i = 0; i < size_t(n); ++i)
using namespace std;

int main(){
	int n, g, n_g, e,ind;//g = gifts, e = for each person
	string name;
	while(!cin.eof()){
		cin >> n;
		vector<string> names;
		int net[n];
		forA(i,n) net[i] = 0;
		while(n--){
			cin >> name;
			names.push_back(name);
		}
		n = names.size();
		while(n--){
			cin >> name >> g;
			cin >> n_g;
			if(n_g){
				e = g / n_g;
				ind = find(names.begin(), names.end(), name) - names.begin();
				net[ind] -= g;
				net[ind] += g % n_g;
			}
			
			while(n_g--){
				cin >> name;
				net[find(names.begin(), names.end(), name) - names.begin()] += e;
			}
		}
		n = names.size();
		forA(i, n) cout << names[i] << ' ' << net[i] << '\n';
		cout << '\n';
	}
}	

//http://www.cplusplus.com/reference/algorithm/find/

//another idea: stores ordered array of names and then store net worth in a map

