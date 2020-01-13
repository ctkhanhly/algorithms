#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, balance = 0, amount;
	string command;
	cin >> T;
	while(T--){
		cin >> command;
		if(command == "donate"){
			cin >> amount;
			balance += amount;
		}
		if(command == "report"){
			cout << balance << "\n";
		}
	}
}
