#include<iostream>
#include<cmath>
#include <iomanip> 
#define M 1000000007
using namespace std;


typedef long long ll;

// SPOJ - LOCKER

ll binomexpmod(ll k) {
    ll res = 1;
    ll n = 3;
    while (k > 0) {
        if (k & 1)
            res = ((res % M) * (n % M)) % M;
        n = ((n % M) * (n % M)) % M;
        k >>= 1;
    }
    return res;
}

int main() {
    ll c, k, ans;
    cin >> c;
    while(c--){
        cin >> k;

        if (k < 3) {
            cout << k << endl;
            continue; 
        }

        if (k % 3 == 1) {
            k = (k - 4)/3;
            ans = 4*binomexpmod(k);
        } else if (k % 3 == 2) {
            k = (k - 2)/3;
            ans = 2*binomexpmod(k);
        } else {
            ans = binomexpmod(k/3);
        }
        ans %= M;
        cout << ans << endl;
    }
}