#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

char arr[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    scanf("%s", arr);
    int len = strlen(arr);
    bool valid = false;

    for (int i = 0; i < len; i++){
        if (arr[i]=='Q'||arr[i]=='H'||arr[i]=='9'){
            valid = true;
            break;
        }
    }
    if (valid){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}