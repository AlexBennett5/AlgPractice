#include<iostream>
#include<cmath>
#include <iomanip> 
using namespace std;

// CodeForces 1 - Parking Lot

long long binomexp(int k) {
    long long res = 1;
    long long n = 4;
    while (k > 0) {
        if (k & 1)
            res = res * n;
        n = n * n;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n; 
    int R = n - 1;
    long long end = binomexp(R - 2);
    long long mid = binomexp(R - 3);


    cout << 4*(6*end + 9*(R-2)*mid) << endl;

    return 0;
}