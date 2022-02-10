#include<iostream>
using namespace std;

int mult(int n, int arr[], int arr_size){
    int carry = 0, prod = 0;

    for (int i = 0; i < arr_size; i++){
        prod = arr[i]*n + carry;
        arr[i] = prod%10;
        carry = prod/10;
    }
    while (carry){
        arr[arr_size] = carry%10;
        carry /= 10;
        arr_size++;
    }
    return arr_size;
}

void fact(int n){
    int arr[1000];
    arr[0] = 1;
    int arr_size = 1;
    for(int i = 2; i <= n; i++){
        arr_size = mult(i, arr, arr_size);
    }
    for (int i = arr_size - 1; i >= 0; i--){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        fact(n);
    }
    return 0;
}