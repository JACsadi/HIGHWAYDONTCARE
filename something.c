#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// #include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k))
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
#define sd(i) scanf("%d", &i)
int n,m;
typedef struct node {
   int edge;
   int* adj;
   bool visited;
   int* c; 
   int p;
} node;
ll dfs(node arr[], int nv) {
  //  printf("%d ", nv);
   arr[nv].visited = 1;
   ll  ans = 100000000000000; 
   f(i, arr[nv].edge) {
   if(!arr[arr[nv].adj[i]].visited) {
    arr[arr[nv].adj[i]].p = arr[nv]
   ll k = dfs(arr,arr[nv].adj[i]);
   if(k == 100000000000000) continue;
   if(k == 10000000000000) {
    ans = k;
    break;
   }
    else ans = ans > k + (ll)arr[nv].c[i] ? k + (ll)arr[nv].c[i] : ans;
   } else{
      a
     return 10000000000000;
     }
   }
   arr[nv].visited = 0;
   if(nv == n && ans != 10000000000000) return 0;
   return ans;
}
int main() {
  sd(n);sd(m);
  node graph[n+1];
  f(i,n+1) {
    graph[i].edge = 0;
    graph[i].adj = ma(int,0);
    graph[i].c = ma(int,0);
    graph[i].visited = 0;
  }
  f(i,m) {
    int a,b,c;
    sd(a);sd(b);sd(c);
    graph[a].edge++;
    graph[a].adj = (int*) realloc(graph[a].adj, graph[a].edge*sizeof(int));
    graph[a].adj[graph[a].edge - 1] = b;
    graph[a].c = (int*) realloc(graph[a].c, graph[a].edge*sizeof(int));
    graph[a].c[graph[a].edge - 1] = -1*c;
  }
  ll ans = dfs(graph, 1);
//   ll ans = 5;
  if(ans == 10000000000000) printf("inf");
  else printf("%lld", ans*-1);
}