#include <iostream>
#include <math.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
int n,sum, idx,l,cnt;
double bal, num;
string res,ans;
int main(){
    scanf("%d", &n);
    FOR(z,n){
        bal = 0.0;
        FOR(i,12){
            scanf("%lf", &num);
            bal += num;
        }
        bal /= 12.0;
        sum = bal/1000;
        l = log10(sum)+1;
        idx = l+1 +l/3;
        res = string(idx, '0');
        cnt = 0;
        while(sum  > 0){
            res[--idx] = '0'+sum%10;
            sum/=10;
            ++cnt;
            if(cnt % 3 == 0 && sum ) res[--idx] = ',';
        }
        ans = res.substr(idx);
        // if(bal > 999.99) printf("%d $%ld,%06.2lf\n", z+1, (int)(bal/1000.0), fmod(bal,1000.0));
        if(bal > 999.99) printf("%d $",z+1), cout  << ans,  printf(",%06.2lf\n", fmod(bal,1000.0));
        else printf("%d %.2fd\n", z+1, bal);
    }
}