#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include<cmath>
using namespace std;

typedef long long ll;

char arr[110];
char res[220];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    scanf("%s", arr);
    int len = strlen(arr);
    int k=0;
    char c;

    for (int i=0; i<len; i++){
        c = tolower(arr[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'){
            continue;
        } else {
            res[k++] = '.';
            res[k++] = c;
        }
    }
    res[k] = '\0';
    printf("%s\n", res);

    return 0;
}