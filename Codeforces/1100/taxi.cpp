#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include<cmath>
using namespace std;

typedef long long ll;

int arr[5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, a, res;
    arr[1] = arr[2] = arr[3] = arr[4] = 0; 
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        arr[a]++;
    }
    res = arr[4];
    int tmp = min(arr[3],arr[1]);
    res += tmp;
    arr[3] -= tmp;
    arr[1] -= tmp;

    res += arr[2]/2;
    arr[2] = arr[2]%2;

    if(arr[1]){
        int rem = 0;
        if(arr[2]){
            rem += 2;
        }
        rem += arr[1];
        res += rem/4;
        rem %= 4;
        if(rem) res++;
    } else if (arr[3]){
        if (arr[2]){
            res++;
        }
        res += arr[3];
    } else if (arr[2]){
        res++;
    }

    printf("%d\n", res);

    return 0;
}
