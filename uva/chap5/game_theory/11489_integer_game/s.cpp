#include <iostream>
#include <string>
using namespace std;


//AC
string n;
int div3, ans,num,T;
int main(){
    cin>> T;
    for(int z = 0; z < T; ++z){
        cin >> n;
        ans = -1;
        div3 = num = 0;
        for(int i = 0 ; i < n.size(); ++i){
            num+= (n[i]-'0');
        }
        for(int i = 0; i < n.size(); ++i){
            if((n[i]-'0') %3==0) div3++;
            if((n[i]-'0') % 3 == num%3) ans = (n[i]-'0');
        }
        printf("Case %d: ", z+1);
        if(ans == -1 || (ans%3 == 0 && div3%2 == 0) || (ans%3 && (div3&1)))
            printf("T\n");
        else printf("S\n");
    }
}