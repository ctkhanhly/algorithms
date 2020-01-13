#include <iostream>
#include <string>
using namespace std;

int main(){
	int c = 1;
	string term;
	while(cin >> term && term != "*"){
		if(term == "Hajj") cout << "Case " << c << ": Hajj-e-Akbar\n";
		if(term == "Umrah") cout << "Case " << c << ": Hajj-e-Asghar\n";		++c;
	}
}
