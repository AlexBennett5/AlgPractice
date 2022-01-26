//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// UVa 1230 - MODEX

long long binomexp(long long a, long long b, long long n){
    a %= n;
    long long res = 1;
    while(b > 0){
        if (b & 1)
            res = res * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    
    long long a, b, n;
    while(c--){
        cin >> a >> b >> n;
        long long res = binomexp(a,b,n);
        cout << res << endl;
    }
}