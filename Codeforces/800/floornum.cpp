#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, x, cnt;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &n, &x);

        if (n==1||n==2){
            printf("1\n");
        } else {
            cnt = 1;
            while(n>=3){
                n -= x;
                cnt++;
            }
            printf("%d\n", cnt);
        }
    }

    return 0;
}