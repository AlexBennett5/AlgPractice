#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,a;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &a);

        if (360%(180-a)){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}


/*

180(n-2)/n = a
1 - 2/n = a/180

1 - a/180 = 2/n
1/(1-a/180) = n/2
n = 2/(1-a/180)

n = 360/(180 - a)

*/