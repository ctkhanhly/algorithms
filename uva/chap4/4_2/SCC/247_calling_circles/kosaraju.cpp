#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;



typedef vector<int> vi;
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
const int N = 25;
int n,m,u,v, order,c, discCnt, numCC;
unordered_map<string, int> idx;

string A,B;
stack<int>* st;
int disc[N];
string names[N];
int low[N];
bool explored[N],start;
vi g[N];

int main(){

}