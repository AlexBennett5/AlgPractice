#include <iostream>
using namespace std;

// CodeChef - FLOW016

long gcd(long a, long b){
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c;
    long a, b, g;
    scanf("%d\n", &c);
    while(c--){
        scanf("%ld %ld\n", &a, &b);
        g = gcd(a,b);
        printf("%ld %ld\n", g, (a/g)*b);
    }
}
