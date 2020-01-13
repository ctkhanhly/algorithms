#include <iostream>
#include <string>
using namespace std;

int  main(){
	int T;
	string s;
	cin >> T;
	while(T--){
		int count = 0;
		cin >> s;
		if(s.size() == 5) cout << 3 << "\n";
		else{
			if(s[0] == 'o') ++count;
			if(s[1] == 'n') ++count;
			if(s[2] == 'e') ++count;
			if(count >= 2) cout << 1 << "\n";
			else cout << 2 << "\n";
		}
	}
}
