#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include<cmath>
using namespace std;

typedef long long ll;

int arr[150010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k, h;
    int curr = 0, minsofar = 0, mindex = 1;

    scanf("%d %d\n", &n, &k);

    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        if (i <= k){
            curr += arr[i];
        }
    }
    minsofar = curr;

    for (int i = k + 1; i <= n; i++){
        curr -= arr[i - k];
        curr += arr[i];

        if (curr < minsofar){
            mindex = i - k + 1;
            minsofar = curr;
        }
    }
    printf("%d\n", mindex);

    return 0;
}

/*

1 1
100

*/