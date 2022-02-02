#include<iostream>
#include<cmath>
#include <iomanip> 
using namespace std;

// UVa 11029 - Leading and Trailing

// O(logn)
int binomexpmod(long n, long k) {
    int res = 1;
    n %= 1000;
    while (k > 0) {
        if (k & 1)
            res = (res * n) % 1000;
        n = (n * n) % 1000;
        k >>= 1;
    }
    return res;
}

int logfirstfew(long n, long k) {
    double x = (double) k * log10(n);
    return pow(10, x - floor(x)) * 100.0;
}

int main() {
    int c;
    cin >> c;
    
    long long n,k, lead, trail;
    while(c--) {
        cin >> n >> k;
        lead = logfirstfew(n, k);
        trail = binomexpmod(n, k);
        cout << lead << "..." << setw(3) << setfill('0') << trail << endl;
    }
    return 0;
}