#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, p, q;
    vector<pair<int, int> > v;
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d\n", &p, &q);
        v.push_back(make_pair(p,q));
    }
    sort(v.begin(), v.end());
    bool qual = false;
    for (int i = 1; i < n; i++){
        if (v[i-1].second>v[i].second){
            qual = true;
            break;
        }
    }
    if (qual){
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }

    return 0;
}


/*

p1 q1
p2 q2
...

There exists laptop where pi<pj && qi>qj

For all laptops, if pi<pj then qi<qj

*/