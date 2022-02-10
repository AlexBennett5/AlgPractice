#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
bool primes[35001];
vector<int> primesUnder35000;

void sieve(){
    primes[0] = primes[1] = false;
    for (int i = 2; i <= 35000; i++){
        primes[i] = true;
    }

    for (ll i = 2; i<=35000; i++){
        if (primes[i]){
            primesUnder35000.push_back(i);
            for (ll j = i*i; j <= 35000; j += i){
                primes[j] = false;
            }
        }
    }
}

bool is_prime(int n){
    if (n <= 35000){
        return primes[n];
    } else {
        for (ll p : primesUnder35000){
            if (n % p == 0) return false;
        }
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    int t;
    ll n, m;
    scanf("%d\n", &t);
    while(t--){
        scanf("%lld %lld\n", &m, &n);
        for (ll i = m; i <= n; i++){
            if (is_prime(i)){
                printf("%lld\n", i);
            }
        }
        if (t>0){
            printf("\n");
        }
    }
    return 0;
}