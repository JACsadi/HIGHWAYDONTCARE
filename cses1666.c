#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
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
} node;
void dfs(node arr[], int nv) {
//   printf("%d ", nv);
   arr[nv].visited = 1;
   f(i, arr[nv].edge) if(!arr[arr[nv].adj[i]].visited) dfs(arr,arr[nv].adj[i]);
}
int main() {
  sd(n);sd(m);
  node graph[n+1];
  f(i,n+1) {
    graph[i].edge = 0;
    graph[i].adj = ma(int,0);
    graph[i].visited = 0;
  }
  f(i,m) {
    int a,b;
    sd(a);sd(b);
    graph[a].edge++;
    graph[a].adj = (int*) realloc(graph[a].adj, graph[a].edge*sizeof(int));
    graph[a].adj[graph[a].edge - 1] = b;
    graph[b].edge++;
    graph[b].adj = (int*) realloc(graph[b].adj, graph[b].edge*sizeof(int));
    graph[b].adj[graph[b].edge - 1] = a;
  }
  int nonvisited = 1;
  int ans = -1;
  int* road = (int*) calloc(n,sizeof(int));
  while(nonvisited != n+1) {
    ans++;
    road[ans] = nonvisited;
    dfs(graph, nonvisited);
    for(int j = nonvisited+1; j <= n+1; j++) {
        if(j > n || !graph[j].visited) {
            nonvisited = j;
            break;
        }
    }
  }
  printf("%d\n", ans);
  for(int i = 1; i <= ans; i++) printf("%d %d\n", road[i-1], road[i]);
  free(road);
}