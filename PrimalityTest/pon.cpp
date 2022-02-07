#include <iostream>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpow(u64 base, u64 e, u64 mod){
    u64 result = 1;
    base %= mod;
    while(e){
        if (e&1) {
            result = (u128) result * base % mod;
        }
        base = (u128) base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s){
    u64 x = binpow(a, d, n);

    //Checking a^d = 1 mod n && a^d = -1 mod n
    if (x==1 || x==n-1){
        return false;
    }

    //Checking for all values of 1<=r<=s-1
    for (int r = 1; r < s; r++){
        x = (u128) x * x % n;
        if (x==n-1)
            return false;
    }
    return true;
}

// Miller Rabin primality test
// For an odd number n (true of all primes >2), n-1 is even and thus
// n - 1 = 2^s*d for odd d.
// We can factor Fermat's little theorem:
// a^n-1 = 1 mod n -> a^(2^s*d) - 1 = 0 mod n
// (a^(2^(s-1)*d) + 1)(a^(2^(s-1)*d) - 1) = 0 mod n
// ...
// (a^(2^(s-1)*d) + 1)(a^(2^(s-2)*d) + 1)...(a^d+1)(a^d-1) = 0 mod n
// If n is prime, it must divide one of these factors
// Thus we check a^d = 1 mod n and a^(2^r)d = -1 mod n for all bases 2<=a<=n-2 and 0<=r<=s-1

// For a 64 bit integer, the test is deterministic by only checking the first 12 prime numbers as bases
bool MillerRabin(u64 n){
    if (n < 2)
        return false;

    int s = 0;
    u64 d = n - 1;
    // Find s and d for 2^s*d = n - 1
    while ((d&1) == 0){
        d >>= 1;
        s++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a)
            return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    u64 n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%llu\n", &n);

        if (MillerRabin(n)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}