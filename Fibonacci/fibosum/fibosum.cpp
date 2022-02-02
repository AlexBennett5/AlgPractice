#include <iostream>
#include <utility>
#define M 1000000007
using namespace std;

typedef long long ll;

// SPOJ - FIBOSUM

//Same function as main74.cpp
//O(logn)
pair<ll,ll> fib(ll n){
    if (n==0){
        return {0LL, 1LL};
    }

    pair<ll,ll> p = fib(n>>1);
    ll c = p.first * (2LL*p.second - p.first) % M;
    ll d = (p.first * p.first + p.second * p.second) % M;

    if (n&1){
        return {d, (c + d) % M};
    } else {
        return {c, d};
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, n, m, ans;
    pair<ll,ll> p;
    scanf("%lld\n", &t);
    while(t--){
        scanf("%lld %lld\n", &n, &m);
        // If S(n) is the sum of all fib integers up to n,
        // then S(n) = F(n+2) - 1
        // Thus S(m) - S(n) = F(m+2) - F(n+2)
        p = fib(n + 1);
        n = p.first;
        p = fib(m + 2);
        m = p.first;
        printf("%lld\n", ((m - n)%M + M)%M);
    }
    return 0;
}