#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, a,b,c,s;
    scanf("%d\n", &n);
    s = 0;
    while(n--){
        scanf("%d %d %d\n", &a, &b, &c);
        if (a+b+c>1){
            s++;
        }
    }
    printf("%d\n", s);

    return 0;
}