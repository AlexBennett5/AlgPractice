#include<iostream>
using namespace std;

int arr[300];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 0; i < 300; i++){
        arr[i] = 0;
    }

    int t,n, lo, hi;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        lo = 0, hi = n-1;
        while(lo<hi){
            printf("%d %d ", arr[lo++], arr[hi--]);
        }
        if (lo==hi){
            printf("%d\n", arr[lo]);
        } else {
            printf("\n");
        }
    }

    return 0;
}