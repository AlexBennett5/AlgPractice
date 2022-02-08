#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef unsigned long long ll;

// SPOJ - FACT0

vector<ll> trial_division(ll n){
    vector<ll> factorization;
    while (n%2 == 0){
        factorization.push_back(2);
        n /= 2;
    }
    for (ll d = 3; d*d <= n; d += 2){
        while (n%d == 0){
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n>1)
        factorization.push_back(n);
    return factorization;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, fact, exp;
    vector<ll> factors;
    
    while(true){
        scanf("%llu\n", &n);
        if (!n){
            break;
        }

        factors = trial_division(n);

        fact = factors[0];
        exp = 0;
        for (int i = 0; i < factors.size(); i++){
            if (factors[i] != fact){
                printf("%llu^%llu ", fact, exp);
                fact = factors[i];
                exp = 1;
            } else {
                exp++;
            }
        }
        printf("%llu^%llu\n", fact, exp);
    }
    return 0;
}