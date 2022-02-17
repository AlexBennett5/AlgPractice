#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char arr[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    scanf("%s", arr);
    int len = strlen(arr);

    int a,b;
    a = b = 0;
    for (int i = 0; i < len; i++){
        if (a>6 || b>6){
            break;
        }

        if (arr[i]=='0'){
            if (b>0) b=0;
            a++;
        } else if (arr[i]=='1'){
            if (a>0) a=0;
            b++;
        }
    }

    if (a>6 || b>6){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}