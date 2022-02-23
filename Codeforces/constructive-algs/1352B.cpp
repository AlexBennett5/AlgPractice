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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,n,k;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &n, &k);

        if (k>n){
            printf("NO\n");
            continue;
        }

        if (n%2==k%2){
            printf("YES\n");
            for(int i=1;i<k;i++){
                printf("1 ");
            }
            printf("%d\n", n-k+1);
        }else if((n%2==0)&&(n>=2*k)){
            printf("YES\n");
            for(int i=1;i<k;i++){
                printf("2 ");
            }
            printf("%d\n", n-2*k+2);
        }else{
            printf("NO\n");
        }

        
    }

    return 0;
}

