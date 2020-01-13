#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


//AC
typedef pair<char,int> ci;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
#define mp make_pair


const int N = 1000000;
string s;
int Q,n,start, en, l,r,m, id,sz,lid;
string fb;
ci arr[N];
bool noAns;
int main(){
    cin >> s;
    n = s.size();
    FOR(i, n) arr[i] = mp(s[i],i);
    sort(arr, arr+n);
    cin >>  Q;
    FOR(q,Q) {
        cin >> fb;
        sz = fb.size();
        id = 0;
        
        noAns = false;
        lid = -1;
        while(id < sz){
            l = 0, r = n;
            //bin search
            while(l < r){
                m = (l+r)/2;
                if(arr[m].fi > fb[id] || (arr[m].fi == fb[id] && arr[m].se > lid)) r = m;
                else l = m+1;
            }
            if(l >= n || arr[l].fi != fb[id] || arr[l].se <= lid){
                noAns = true;
                break;
            }
            if(id == 0) start = arr[l].se;
            if(id == sz-1) en = arr[l].se;
            lid = arr[l].se;
            ++id;
        }
        if(noAns) cout <<  "Not matched\n";
        else cout << "Matched " << start << ' ' << en  << endl;
    }
}