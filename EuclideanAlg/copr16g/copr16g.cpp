#include <iostream>
using namespace std;

typedef long long ll;

// CodeChef - COPR16G

//O(log(min(a,b)))
// Iterative Euclidean algorithm
ll gcd(ll a, ll b){
    if (!a|!b) return a|b;

    // gcd(2a, 2b) = 2*gcd(a,b), so we save this shift 2^k for the end
    unsigned shift = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do{
        // gcd(a,2b) = gcd(a,b), so we can remove unshared factors of two
        b >>= __builtin_ctz(b);
        if (a>b){
            swap(a,b);
        }
        // gcd(a,b) = gcd(b, a-b)
        b -= a;
    }while(b);

    // once b=0, then a=gcd >> shift, so we shift the answer left
    return a << shift;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t, a, b, n;
    scanf("%lld\n",&t);
    while(t--){
        scanf("%lld %lld\n",&a,&b);
        
        // If one of the numbers is 1 then any positive integer can be constructed
        if (a==1 || b==1){
            printf("%d\n", 0);
            continue;
        }
        
        // If a and b are coprime, then the solution is their Frobenius number + 1
        // If a and b are not coprime, then no Frobenius number exists
        n = gcd(a,b);
        if (n == 1){
            printf("%lld\n", a*b - a - b + 1);
        } else {
            printf("%d\n", -1);
        }
    }
}