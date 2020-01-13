#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long int li;
int main(){
	int N, H, W, w;
	li B, p, a, curr_ans = 0;
	while(!cin.eof()){
		cin >> N >> B >> H >> W;
		vector<li> ans;
		while(H--){
				cin >> p;
			curr_ans = 0;
			w = W;	
			while(w--){
				cin >> a;
				if(a >= N){
					curr_ans = p * N;
				}
			}
			if(curr_ans > 0 && curr_ans <= B) ans.push_back(curr_ans);
		}
		sort(ans.begin(), ans.end());
		if(ans.size() == 0) cout << "stay home\n";
		else cout << ans.back() << "\n";
	}
}
