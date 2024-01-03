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
   int count;
   int p; 
} node;
void bfs(node arr[]) {
   arr[n].visited = 1;
   int siz = 1;
   ima(com,int,siz);
   com[0] = n; 
   f(i,siz) {
    f(j,arr[com[i]].edge) {
        if(!arr[arr[com[i]].adj[j]].visited) {
            arr[arr[com[i]].adj[j]].visited = 1;
            siz++;
            com = (int*) realloc(com,n*sizeof(int));
            com[siz-1] = arr[com[i]].adj[j];
            arr[arr[com[i]].adj[j]].count = arr[com[i]].count +1;
            arr[arr[com[i]].adj[j]].p = com[i];
            if(com[siz-1] == 1) break;
        }
    }
   }
   if(arr[1].p == -1) printf("IMPOSSIBLE");
   else {
    printf("%d\n", arr[1].count);
    int z = 1;
    while(z != -1) {
        printf("%d ", z);
        z = arr[z].p;
    }
    } 
}
int main() {
  sd(n);sd(m);
  node graph[n+1];
  f(i,n+1) {
    graph[i].edge = 0;
    graph[i].adj = ma(int,0);
    graph[i].visited = 0;
    graph[i].p = -1;
    graph[i].count = 1;
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
   bfs(graph);
}