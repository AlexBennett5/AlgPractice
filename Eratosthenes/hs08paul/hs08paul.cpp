#include <iostream>
#include <vector>
#include <cmath>
#define M 10000001
using namespace std;

vector<char> is_prime(M + 1, true);
vector<int> ans(M + 1, 0);

// SPOJ - HS08PAUL

void sieve(){
    int n = sqrt(M);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < n; i++){
        if (is_prime[i]){
            for (int j = i*i; j < M; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

// Find all possible n that satisfy x^2 + y^4 = n
void erdos(){
    int p, q, sum;
    for (int i = 0; (p=i*i*i*i) < M; i++){
        for (int j = 0; (q=j*j) < (M - p); j++){
            sum = p + q;
            if (is_prime[sum]){
                ans[sum] = 1;
            }
        }
    }
    for (int i = 1; i < M; i++){
        ans[i] += ans[i - 1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Precompute all possible values of n
    // After this upfront calculation, we can retrieve answers in O(1)
    sieve();
    erdos();

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}