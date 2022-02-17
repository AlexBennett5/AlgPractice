#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include<cmath>
using namespace std;

typedef long long ll;

int binsearch(int arr[], int n, int t){
    int lo=0, hi=n-1, mid;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;

        if (t<arr[mid]){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return hi+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,q,m,k;
    scanf("%d\n", &n);

    int arr[n];

    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);

    scanf("%d\n", &q);
    while(q--){
        scanf("%d\n", &m);
        if (m<arr[0]){
            printf("0\n");
            continue;
        }

        if (m>arr[n-1]){
            printf("%d\n", n);
            continue;
        }
        printf("%d\n", binsearch(arr,n,m));
    }

    return 0;
}
