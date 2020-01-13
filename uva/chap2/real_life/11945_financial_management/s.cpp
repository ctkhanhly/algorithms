#include <iostream>
#include <math.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,sum, idx,l,cnt;
double bal, num;
string res, ans;
int main(){
    scanf("%d", &n);
    FOR(z,n){
        bal = 0;
        FOR(i,12){
            scanf("%lf", &num);
            bal += num;
        }
        bal /= 12;
        // printf("%.4lf\n", bal);
        // cout << bal << endl;
        // bal += 0.005;
        sum = bal*1000;
        sum += 5;
        sum /=10;
        // printf("%.4lf\n", bal);
        // cout << bal << endl;
        // cout << sum << endl;
        l = log10(sum)+1;
        idx = l+1 +(l-2)/3;
        // cout << idx << endl;
        res = string(idx, '0');
        --idx;
        if(sum % 100 ) res[idx--] = '0'+sum%10,sum/=10, res[idx--] = '0'+sum%10, sum /=10,  res[idx--] = '.';
        cnt = 0;
        while(sum  > 0){
            res[idx--] = '0'+sum%10;
            sum/=10;
            ++cnt;
            if(cnt % 3 == 0) res[idx--] = ',';
        }
        // cout << res << endl;
        // cout << idx << endl;
        ans.clear();
        ans = res.substr(idx+1);
        cout << z+1 << " $" << ans << endl;
    }
}