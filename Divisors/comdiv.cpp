#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b){
    if (!a || !b){
        return (a|b);
    }
    unsigned shift = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do{
        b >>= __builtin_ctz(b);
        if (a>b)
            swap(a,b);
        b -= a;
    }while(b);
    return a << shift;
}

int divisor(int n){
    int res = 0, nsqrt = sqrt(n);
    for (int i=1; i <= nsqrt; i++){
        if (n%i == 0){
            if (n/i == i){
                res++;
            } else {
                res += 2;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, a, b, g;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &a, &b);
        g = gcd(a, b);
        printf("%d\n", divisor(g));
    }
    return 0;
}