#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Simple Sieve of Eratosthenes
// O(nloglogn)
vector<char> sieve_primes(int n){
    // All possible composite numbers <=n will have at most a factor of sqrt(n)
    int nsqrt = sqrt(n);

    // vector<char> is slightly faster than vector<bool> for large values of n
    // since modern architecture works more efficiently with bytes than bits
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i*i < n; i++){
        if (is_prime[i]){
            for (int j = i*i; j<n; j+= i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<char> is_prime = sieve_primes(100000000LL);

    int ptr = 100;
    for (int i = 2; i < 100000000; i++){
        if (is_prime[i]){
            if (ptr == 100){
                printf("%d\n", i);
                ptr = 1;
            } else {
                ptr++;
            }
        }
    }
    
    return 0;
}