#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int arr[55] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,n,m,odds,evens;
    bool check=false;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        odds = evens = 0;
        for (int i=0;i<n;i++){
            scanf("%d", &arr[i]);
            if(arr[i]%2){
                odds++;
            }else{
                evens++;
            }
        }
        if ((odds%2)!=(evens%2)){
            printf("NO\n");
        } else if (odds%2==0) {
            printf("YES\n");
        } else {
            sort(arr, arr+n);
            check=false;
            for (int i=0;i<n-1;i++){
                if (arr[i]==arr[i+1]-1){
                    check=true;
                    break;
                }
            }
            if(check){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }

    return 0;
}

/*

Two numbers similar if same parity or differ by one

If (evens%2==0)&&(odds%2==0) => true
If (evens%2!=odds%2) => false
If (evens%2==1)&&(odds%2==1) => If two consecutive numbers exist, then true



11 14 16 12
11 12 14 16


*/