//#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<map>
#define M 10000007
using namespace std;

typedef long long ll;

ll binexp(ll n, ll k) {
    ll res = 1;
    n %= M;
    while(k > 0){
        if (k & 1)
            res = (res*n)%M;
        n = (n*n)%M;
        k >>= 1;
    }
    return res%M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, z;
    scanf("%lld%lld",&n,&k);
    while(n && k){
        z = (2*binexp(n-1,n-1) + binexp(n,n) + 2*binexp(n-1,k) + binexp(n,k))%M;
        printf("%lld\n",z);
        scanf("%lld%lld",&n,&k);
    }
    return 0;
}