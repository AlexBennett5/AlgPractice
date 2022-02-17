#include<iostream>
#include<algorithm>
using namespace std;

int arr[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, tot, curr, k;
    tot = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        tot += arr[i];
    }
    sort(arr, arr+n, greater<int>());
    curr = 0;
    k = 0;
    while(k < n){
        curr += arr[k++];
        if (curr > tot/2){
            break;
        }
    }
    printf("%d\n", k);

    return 0;
}

