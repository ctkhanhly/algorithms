#include <iostream>
#include <string>
using namespace std;

const int L = 10;//lumberjacks
int main(){
	int N, comp, lumbers, lumber1, lumber2;
	string ans;
	cin >> N;
	cout << "Lumberjacks:\n";
	while(N--){
		lumbers = L - 2;
		cin >> lumber1 >> lumber2;
		comp = lumber2 - lumber1;
		comp = comp > 0 ? 1 : -1;
		lumber1 = lumber2;
		ans = "Ordered\n";
		while(lumbers--){
			cin >> lumber2;
			if((lumber2 - lumber1 > 0 && comp < 0) || (lumber2 - lumber1 < 0  && comp > 0)) ans= "Unordered\n";
			lumber1 = lumber2;
		}
		cout << ans;
	}
}
		
