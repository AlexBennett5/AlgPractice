#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, m, a;
    scanf("%lld %lld %lld\n", &n, &m, &a);
    n = n % a == 0 ? n/a : n/a + 1;
    m = m % a == 0 ? m/a : m/a + 1;
    
    printf("%lld\n", n*m);

    return 0;
}
