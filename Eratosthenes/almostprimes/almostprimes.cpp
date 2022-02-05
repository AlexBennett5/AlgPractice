#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sieve(int n){
    int ans = 0;

    vector<char> is_prime(n + 1, true);
    vector<int> factors(n + 1, 0);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++){
        if (is_prime[i]){
            for (int j = i+i; j <= n; j += i){
                is_prime[j] = false;
                factors[j]++;
            }
        }

        if (factors[i]==2){
            ans++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    scanf("%d\n", &n);
    printf("%d\n", sieve(n));

    return 0;
}