#include<iostream>
using namespace std;

typedef long long ll;

ll zeros(ll n){
    ll tot = 0;
    while(n>0){
        tot += (n/5);
        n /= 5;
    }
    return tot;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%lld\n", &n);
        printf("%lld\n", zeros(n));
    }
    return 0;
}