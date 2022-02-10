#include<iostream>
using namespace std;

int reverse(int a){
    int res = 0;
    while(a>0){
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &a, &b);
        a = reverse(a);
        b = reverse(b);
        printf("%d\n", reverse(a+b));
    }
}