#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    scanf("%d\n", &n);
    if (n!=2 && n%2==0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}