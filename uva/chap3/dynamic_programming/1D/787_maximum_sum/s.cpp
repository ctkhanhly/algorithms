#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
const int N = 100;
const int STOP = -999999;
const int INF = 1e6;
const int SIZE = 600+100;
int nums[N],sz;
bool isNeg;
// int32_t pos, prod,sz,neg,currProd;
int pos[SIZE], posn, neg[SIZE], negn, prod[SIZE],prodn,temp[SIZE],carry,k,base;


void reset(int* num, int& n, int other){
    // cout << "reset(int* num, int& n, int other)\n";
    string others = to_string(other);
    n = others.size();
    FOR(i, n) num[i] = others[i]-'0';
    // FOR(i,n) cout << num[i];
    // cout << ' ' << others << endl;
}
void helper(int* num, int n, int other, int pos){
    // int t = 0;
    // carry = 0;
    // for(int i = n-1; i >= 0; --i) temp[t]+= num[i]*other, carry = temp[t]/10, temp[t] %= 10,++t;
    // if(carry) temp[t++] = carry;
    // k = max(k,t);
    // reset(temp, k, curr*other);
    int t = 0;
    carry = 0;
    
    for(int i = n-1; i >= 0; --i){
        t = n-i-1+pos;
        temp[t] += num[i] * other +carry;
        carry = temp[t] /10;
        temp[t] %=10;
        k = max(k,t+1);
    }
    // while(carry > 0)
    t = n + pos;
    while(carry > 0) temp[t] += carry, carry = temp[t]/10, temp[t] %=10, ++t, k=max(k,t);
}
void mult(int* num, int n, int other){
    
    // string others = to_string(other);
    // int i = n-1, j = others.size()-1, t = 0;
    // cout << "mult " <<  n << endl;
    // k = carry = 0;
    
    // for(int j = others.size()-1; j >= 0; --j){
    //     t = 0;
    //     for(int i = n-1; i >= 0; --i){
    //         if(i>=0 && j>=0) temp[t] = num[i]*(others[j]-'0') + carry, --i, --j;
    //         else if(i >= 0) temp[t] = num[i] +carry, --i;
    //         else temp[t] = (others[j]-'0') + carry, --j;
    //         carry = temp[t] /10;
    //         temp[t] = temp[t] %10;
    //         ++t;
    //         k = max(k,t);
    //     }
    // }
    k = (n+1)*(log10(other)+2);
    FOR(i,min(k,SIZE)) temp[i] = 0;
    k = 0;
    int pos = 0;
    // curr = 0;
    // for(int i = n-1; i >= 0; --i) curr = curr*10 +num[i];
    while(other > 0) helper(num, n, (other%10), pos), other/=10, ++pos;
}

void copyFromMult(int* num, int& n){
    // cout << "copyFromMult(int* num, int& n)\n";
    FOR(t,k) num[k-t-1] = temp[t];
    n = k;
}

void reset(int* num, int& n, int* other, int othern){
    // cout << "reset(int* num, int& n, int* other, int othern)\n";
    n = othern;
    FOR(i, n) num[i] = other[i];
}
bool isGreater(int* num1, int n1, int* num2, int n2){
    // cout << "isGreater(int* num1, int n1, int* num2, int n2) "  << n1 << ' ' << n2 << endl;
    if(num1[0] > 0 && num2[0] < 0) return 1;
    else if(num1[0] < 0 && num2[0] > 0) return 0;
    bool bothNeg = (num1[0] < 0) && (num2[0] < 0);
    if(n1 == n2){
        FOR(i,n1) if(num1[i] != num2[i]) return (bothNeg ? num1[i] < num2[i] : num1[i] > num2[i]);
    }
    return (bothNeg ? n1 < n2 : n1 > n2);
}
bool isGreater(int* num, int n, int other){
    // cout << "isGreater(int* num, int n, int other)\n";
    string others = to_string(other);

    // if(num[0] > 0 && (others[0]-'0' < 0)) return 1;
    // else if(num[0] < 0 && (others[0]-'0' > 0)) return 0;
    // bool bothNeg = num[0] < 0 && (others[0]-'0' < 0);

    if(n == others.size()){
        // FOR(i,n) if(num[i] != others[i]) return (bothNeg ? num[i] < (others[i]-'0') : num[i] > (others[i]-'0'));
        FOR(i,n) if(num[i] != others[i]) return num[i] > (others[i]-'0');
    }
    // return bothNeg ? n < others.length() : n > others.length();
    return n > others.length();
} 
int main(){
    while(scanf("%d", &nums[0]) ==1){
        if(nums[0] == STOP) continue;
        sz = 1;
        while(scanf("%d", &nums[sz]) && nums[sz++] != STOP){}
        --sz;
        pos[0] = neg[0] = posn = negn = 1;
        // prod[0] = -INF;
        prodn = 7;
        FOR(i,7) prod[i] = 0;
        prod[0] = -1;
        isNeg = 0;
        FOR(i, sz) {
            // cout << i << endl;
            if(nums[i] >= 0) {
                // pos = max(pos*nums[i],nums[i]), prod = max(prod, pos);
                mult(pos, posn, nums[i]);
                if(isGreater(temp,k, nums[i])) copyFromMult(pos, posn);
                else reset(pos, posn, nums[i]);

                if(isGreater(pos, posn, prod, prodn)) reset(prod, prodn, pos, posn);
            }
            // neg*= nums[i];
            isNeg ^= (nums[i] < 0);
            neg[0] = max(neg[0], -neg[0]);
            mult(neg, negn, max(nums[i], -nums[i]));
            copyFromMult(neg, negn);
            // FOR(i,negn) cout << neg[i];
            // cout << endl;
            // prod = max(prod, neg);
            // pos = max(pos, neg);
            if(isNeg) neg[0] = -neg[0];
            if(isGreater(neg, negn, prod, prodn)) reset(prod, prodn, neg, negn);
            if(!isNeg && isGreater(neg, negn, pos, posn)) reset(pos, posn, neg, negn);

            // if(neg > 0 && nums[i] < 0) neg = nums[i];
            if(!isNeg && nums[i] < 0) reset(neg, negn, -nums[i]), isNeg = 1;
        }

        // currProd = 1;
        // prod = -INF;
        // FOR(i,sz){
        //     currProd = max(currProd*nums[i], nums[i]);
        //     prod = max(prod, currProd);
        // }
        // cout << prod << endl;
        // cout << prodn << endl;
        FOR(i, prodn) cout << prod[i];
        cout << endl;
    }
}