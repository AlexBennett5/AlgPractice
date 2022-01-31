#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if (!a || !b) return a|b;
    unsigned shift = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do{
        b >>= __builtin_ctz(b);
        if(a>b){
            swap(a,b);
        }
        b -= a;
    }while(b);
    return a << shift;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, g, t, tot;
    scanf("%lld\n", &t);
    tot = t + 1;
    while(t){
        scanf("%lld %lld %lld\n", &a, &b, &c);
        g = gcd(a,b);
        if (c%g){
            printf("Case %d: No\n", tot - t);
        } else {
            printf("Case %d: Yes\n", tot - t);
        }
        t--;
    }
}
