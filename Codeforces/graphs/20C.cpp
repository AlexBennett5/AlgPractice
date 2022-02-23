#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int>  ii;

const int INF = INT_MAX;
const int nmax = 100005;
vector<vector<ii> > adjList;

// d: Length of shortest path from from node S to to node v in d[v]
// p: For every vertex v!=s, p[v] is penultimate vertex in the shortest path from s to v.
// Thus shortest path is (s,...,p[p[v]],p[v],v)
int n, d[nmax], p[nmax];
bitset<nmax> marked;


bool dijkstra(int s, int t){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    fill(d, d+n+1, INF);

    pq.push(ii(0,s));
    d[s]=0;
    p[s]=-1;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(u==t) return true;
        marked[u]=true;

        for(auto &pr : adjList[u]) {
            int v = pr.first, w = pr.second;
            printf("v is %d, w is %d\n",v,w);

            if(!marked[v] && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(ii(d[v], v));
                p[v] = u;
            }
        }
    }
    return false;
}

vector<int> restore_path(int s, int t) {
    vector<int> path;

    for (int v = t; v != -1; v = p[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int m,u,v,w;
    scanf("%d %d\n", &n, &m);

    adjList.resize(n+3);
    
    while(m--){
        scanf("%d %d %d\n", &u, &v, &w);
        adjList[u].push_back(ii(u,w));
        adjList[v].push_back(ii(v,w));
    }

    if(dijkstra(1,n)){
        vector<int> path = restore_path(1,n);
        for(int i=0;i<path.size();i++){
            printf("%d ", path[i]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }

    return 0;
}