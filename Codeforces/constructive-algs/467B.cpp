#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int setbits(int a){
    int cnt=0;
    while(a){
        a = a&(a-1);
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m,k;
    scanf("%d %d %d\n", &n, &m, &k);

    int arr[m+2];

    for (int i=1;i<=m+1;i++){
        scanf("%d\n", &arr[i]);
    }

    int cmp = arr[m+1], ans=0;
    for (int i=1;i<m+1;i++){
        if (setbits(cmp^arr[i])<=k){
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}