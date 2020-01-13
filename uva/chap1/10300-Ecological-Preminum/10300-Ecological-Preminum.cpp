#include <iostream>
using namespace std;

int main(){
	int T, F, farmSize, numOfAnimals, sum = 0, EnvFriendFac;
	cin >> T;
	while(T-- > 0){
		cin >> F;
		sum = 0;
		while(F-- > 0){
			cin >> farmSize >> numOfAnimals >> EnvFriendFac;
			sum += farmSize * EnvFriendFac;
		}
		cout  << sum << "\n";
	}
}
