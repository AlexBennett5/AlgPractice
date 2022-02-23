#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;

typedef long long ll;

int arr[100005] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,n,i,j;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        for(int i=0;i<n;i++){
            scanf("%d ", &arr[i]);
        }
        sort(arr,arr+n);
        i=0,j=n-1;
        if (n%2){
            printf("%d ", arr[(n-1)/2]);
            i=(n-1)/2-1;
            j=(n-1)/2+1;
        }else{
            j=n/2;
            i=j-1;
        }
        while(i>=0&&j<n){
            printf("%d %d ",arr[i--],arr[j++]);
        }
        printf("\n");
    }

    return 0;
}