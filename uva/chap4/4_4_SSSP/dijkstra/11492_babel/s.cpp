#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;


//WRONG INF value took entire day to debug
//AC
typedef vector<int> vi;
typedef pair<int,int> ii;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define fi first
#define se second
#define DEBUG

const int M = 2001;
const int INF = 100005;

//not neccessarily 2000*50 b/c if 2 words satisfy lang but 
//does not satisfy 
//can a word be added twice?
//no - words are distinct in any pair
//at lang C word P -> only connects to 1 other lang
//either added b/c no same begining, or don't
//=> path cannot be repeated

struct Word{
    int l1,l2;
    char str;
};
int m, s, t, lacnt, wo, la, len, vla,nwo, ans,c,e;
string O,D, I1,I2, P;
Word vocab[M];//quick search for pair rather than pair of word, otherLang
int cost[M];
int dist[2*M][27];
vi lang[2*M];

#ifndef DEBUG
ii p[M];
ostream& operator<<(ostream& os, const Word& w){
    os << w.l1 << ' ' << w.l2 << ' ' << w.str;
    return os;
}
#endif

void dijkstra(){
    FOR(i, lacnt) FOR(j,27) dist[i][j] = INF;

    set<pair<int,ii>> st;
    st.insert({0, {s, m } });
    dist[s][26] = 0;
    vocab[m].str = 'a'+26;
    ans = -1;
    while(!st.empty()){
        len = st.begin()->fi, la = st.begin()->se.fi, wo = st.begin()->se.se;
        e = vocab[wo].str - 'a';
        st.erase(st.begin());
        //I also use a set so it doesn't matter
        if(len > dist[la][e]) continue; //- a language may be visited many times
        // vla = vocab[wo].l1 == la ? vocab[wo].l2 : vocab[wo].l1;
        // cout << len << ' ' << la << ' ' << wo << ' ' << lang[la].size() << endl;

        if(la == t) { ans = dist[la][ e ]; break;}
        FOR(i, lang[la].size()){
            nwo = lang[la][i];
            c = vocab[nwo].str-'a';

            //???
            // if((vocab[nwo].l1 == t || vocab[nwo].l2 == t ) && nwo == wo) {//{ ans = dist[la][ e ]; break;}
            //     st.insert({len, {t, nwo}});
            // }

            vla = vocab[nwo].l1 == la ? vocab[nwo].l2 : vocab[nwo].l1;

            #ifndef DEBUG
            cout << la << ' ' << vla  << ' ' << vocab[nwo] << ' ' << vocab[wo] << ' ';
            cout << dist[la][ e ] + cost[nwo] << ' ' << dist[vla][c] << endl;
            #endif

            if(vocab[nwo].str == vocab[wo].str) continue;
            
            //self-connection
            // if(dist[la][e] + cost[nwo] < dist[la][c]){
            //     st.erase({dist[la][c], {la, nwo}});//should be dist[la][wo]
            //     dist[la][c] = dist[la][ e ] + cost[nwo];
            //     st.insert({dist[la][c], {la, nwo}});
            // }
            
            if(dist[la][ e ] + cost[nwo] < dist[vla][c]){

                #ifndef DEBUG
                    cout << la << ' ' << vla  << ' ' << vocab[nwo] << ' ' << vocab[wo] << ' ' << dist[vla][c]<< endl;
                p[vla] = {la,e};//parent needs 2 states as well
                if(la == 0 && vla == 11) cout << la << ' ' << vla << ' ' << dist[la][c] + cost[nwo] << ' ' << cost[nwo] << endl;
                if(la == 11 && vla == 10) cout << la << ' ' << vla << ' ' << dist[la][c] + cost[nwo] << ' ' << cost[nwo] << endl;
                if(la == 10 && vla == 8) cout << la << ' ' << vla << ' ' << dist[la][c] + cost[nwo] << ' ' << cost[nwo] << endl;
                if(la == 8 && vla == 9) cout << la << ' ' << vla << ' ' << dist[la][c] + cost[nwo] << ' ' << cost[nwo] << endl;
                if(la == 9 && vla == 1) cout << la << ' ' << vla << ' ' << dist[la][c] + cost[nwo] << ' ' << cost[nwo] << endl;
                #endif

                st.erase({dist[vla][c], {vla, nwo}});
                dist[vla][c] = dist[la][ e ] + cost[nwo];
                st.insert({dist[vla][c], {vla, nwo}});
                
            }
        }
    }
}

//duplicate? if I arrive at amigo and my last lang is english and my finish
//lang is spanish => I don't really have to pay more to get to spanish, I'm already there!

int main(){
    while(cin >> m, m){
        
        cin >> O >> D;
        unordered_map<string,int> langMap;
        lacnt = 2;
        langMap[O] = s = 0, langMap[D] = t = 1;
        FOR(i, m){
            cin >> I1 >> I2 >> P;

            if(langMap.count(I1)) lang[ langMap[I1] ].pb(i);
            else langMap[I1] = lacnt, lang[lacnt++].pb(i);

            if(langMap.count(I2)) lang[ langMap[I2] ].pb(i);
            else langMap[I2] = lacnt, lang[lacnt++].pb(i);

            //self-connect
            cost[i] = P.length();
            // cout << cost[i] << endl;
            vocab[i] = {langMap[I1],langMap[I2], P[0]};

        }

        #ifndef DEBUG
        FOR(i, lacnt) { FOR(j, lang[i].size()) cout << lang[i][j] << ' '; cout << endl; }
        FOR(i, m) cout << vocab[i];
        cout << s << ' ' << t << endl;
        #endif

        dijkstra();
        if(ans == -1) cout << "impossivel" << endl;
        else cout << ans << endl;
        FOR(i, lacnt) lang[i].clear();

        #ifndef DEBUG
        //pjklbzjqvipuxlppshfpwvfsuuundemarjkvrfqihnrqpdftt
        //3-4-5-7-13-
        //4,8,18,15,4
        //1 9 8 10 11 0
        la = t;
        while(la != s) cout << la << ' ', la = p[la].fi, e = p[la].se;
        cout << endl;
        cout << cost[3] << ' ' << cost[4] << ' ' << cost[5] << ' ' << cost[7] << ' ' << cost[13] << endl;
        #endif
    }
}