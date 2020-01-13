#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, N, c, ans, cs = 1;
	cin >> T;
	while(T--){
		cin >> N;
		ans = 0;
		while(N--){
			cin >> c;
			ans = max(ans, c);
		}	
		cout << "Case " << cs++ << ": " << ans << "\n";
	}
}
