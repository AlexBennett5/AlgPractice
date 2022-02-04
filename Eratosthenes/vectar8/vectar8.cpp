#include <iostream>
#include <vector>
#include <cmath>
#define M 10000001
using namespace std;

typedef long long ll;

template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

vector<char> is_prime(M + 1, true);
vector<int> ans(M + 1, 0);

// SPOJ - VECTAR8

void sieve(){
    int n = sqrt(M);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < n; i++){
        if (is_prime[i]){
            for (int j = i*i; j < M; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

bool is_primal(ll n){
    ll digits = 0;
    ll num = n;
    while(num > 0){
        // Check if number contains a zero
        if (num%10 == 0){
            return false;
        }
        digits++;
        num /= 10;
    }
    // Use binary exponentiation here
    ll div = exp(10LL, digits - 1);

    while(n > 0){
        n %= div;
        div /= 10;
        if((n != 0 && !is_prime[n])){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Precompute answers up to M
    sieve();
    for (int i = 2; i <= M; i++){
        ans[i] = ans[i-1];
        if (is_prime[i]){
            if (is_primal(i)){
                ans[i]++;
            }
        }
    }

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}