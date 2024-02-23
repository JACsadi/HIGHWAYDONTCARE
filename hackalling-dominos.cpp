#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <iostream>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf(" %d", &i)
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a > b ? b : a;
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define inf 1000000000
using namespace std;
typedef struct node {
  int edge;
  int* adj;
  int* adjvalue;
  int dist;
} node;
void ds(node g[], int s) {
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,s});
  while(!pq.empty()) {
    pair<int,int> top = pq.top();
    pq.pop();
    int index = top.second;
    f(i, g[index].edge) {
      int next = g[index].adj[i];
      int val = Max(g[index].adjvalue[i],g[index].dist);
      if(g[next].dist > val) {
        g[next].dist = val;
        pq.push({val,next});
      }
    }
  }
}
int main() {
  tcase{
  int n,m;
  sd(n);sd(m);
  node g[n];
  f(i,n) {
    g[i].edge = 0;
    g[i].adj = ma(int,0);
    g[i].adjvalue = ma(int,0);
    g[i].dist = inf;
  }
  f(i,m) {
    int u,v,w;
    sd(u);sd(v);sd(w);
    g[u].edge++;
    g[u].adj = (int*) realloc(g[u].adj, g[u].edge*sizeof(int));
    g[u].adjvalue = (int*) realloc(g[u].adjvalue, g[u].edge*sizeof(int));
    g[u].adj[g[u].edge-1] = v;
    g[u].adjvalue[g[u].edge-1] = w;
    g[v].edge++;
    g[v].adj = (int*) realloc(g[v].adj, g[v].edge*sizeof(int));
    g[v].adjvalue = (int*) realloc(g[v].adjvalue, g[v].edge*sizeof(int));
    g[v].adj[g[v].edge-1] = u;
    g[v].adjvalue[g[v].edge-1] = w;
  }
  int s; sd(s);
  g[s].dist = 0;
  ds(g,s);
  printf("Case %d:\n", casee);
  f(i,n) {
    if(g[i].dist == inf) printf("Impossible\n");
    else printf("%d\n", g[i].dist );
  }
  }
  return 0;
}