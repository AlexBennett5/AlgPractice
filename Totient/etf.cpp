#include<iostream>
using namespace std;

typedef long long ll;

// Number of integers between 1 and n inclusive which are coprime to n
ll totient(ll n){
    ll result = n;
    for (ll i = 2; i*i <= n; i++){
        if (n%i == 0){
            while (n%i == 0){
                n /= i;
            }
            result -= result/i;
        }
    }
    if (n>1){
        result -= result/n;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    ll n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%lld\n", &n);
        printf("%lld\n", totient(n));
    }
    return 0;
}