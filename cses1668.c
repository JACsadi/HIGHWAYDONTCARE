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
   int G; 
} node;
int bfs(node arr[], int k) {
   arr[k].visited = 1;
   int siz = 1, flag = 1;
   ima(com,int,siz);
   com[0] = k; 
   arr[k].G = 2;
   f(i,siz) {
    f(j,arr[com[i]].edge) {
        if(!arr[arr[com[i]].adj[j]].visited) {
            arr[arr[com[i]].adj[j]].visited = 1;
            siz++;
            com = (int*) realloc(com,n*sizeof(int));
            com[siz-1] = arr[com[i]].adj[j];
            arr[arr[com[i]].adj[j]].G = (arr[com[i]].G&1) +1;
        } else if(arr[arr[com[i]].adj[j]].G == arr[com[i]].G) {
            flag = 0; break;
        }   
    }
    if(!flag) break;
   }
   free(com);
   return flag;
}
int main() {
  sd(n);sd(m);
  node graph[n+1];
  f(i,n+1) {
    graph[i].edge = 0;
    graph[i].adj = ma(int,0);
    graph[i].visited = 0;
    graph[i].G = 0;
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
    int k = 1;
   f(i,n+1) {
    if(graph[i].edge != 0 && !graph[i].visited) {
       k = bfs(graph, i);
       if(!k) break;
    }
   }
   if(!k) printf("IMPOSSIBLE");
   else {
     for(int i = 1; i<=n;i++) printf("%d ", graph[i].G == 1 ? 1 : 2);
   }
}