#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	char c; string s;
	while(n--){
		cin >> s;
		
		if(s == "1"  || s == "4"  || s == "78"){
			cout << "+\n";
		}
		else if(s.substr(s.size()-2) == "35"){
			cout << "-\n";
		}
		else if(s[0] == '9' && s[s.size()-1] == '4'){
			cout << "*\n";
		}
		else if(s.substr(0,3) == "190"){
			cout << "?\n";
		}
		else{
			//if(s[s.size()-2]  == '3' || s[s.size()-1] == '5'){
			//	cout << "-\n";
			//}
			//else if(s[s.size()-1] == '4' || s[0] == '9'){
			//	cout << "*\n";
			//}
			//else{
			//	cout << "?\n";
			//}
			cout << "+\n";
		}
	}
}
