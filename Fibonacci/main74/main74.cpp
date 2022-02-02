#include <iostream>
#include <utility>
#define M 1000000007
using namespace std;

typedef long long ll;

// SPOJ - MAIN74

//Returns Fibbonacci numbers (F_n, F_n+1)
pair<ll, ll> fib(ll n){
    if (n == 0){
        return {0LL, 1LL};
    }

    // Let n = 2k. Find F_k, F_k+1
    pair<ll, ll> p = fib(n >> 1);

    // F_n = F_2k = F_k*(2*F_k+1 - F_k)
    ll c = p.first * (2LL*p.second - p.first) % M;

    // F_n+1 = F_2k+1 = F_k^2 + F_k+1^2
    ll d = (p.first * p.first + p.second * p.second)%M;

    // If n is odd, then F_n will actually be F_n+1 above, so we take the next fib number
    if (n&1){
        return {d, (c + d)%M};
    } else {
        return {c, d};
    }
}

int main(){
    ll t, n;
    pair<ll, ll> p;
    scanf("%lld\n", &t);
    while(t--){
        scanf("%lld\n", &n);

        // Degenerate cases
        if(n==0){
            printf("0\n");
            continue;
        }
        if (n==1){
            printf("2\n");
            continue;
        }

        // According to Lame's Theorem, the expected result is the fib numbers F_n+1 + F_n+2;
        p = fib(n+1);
        printf("%lld\n", ((p.first + p.second)%M + M)%M);
    }
}