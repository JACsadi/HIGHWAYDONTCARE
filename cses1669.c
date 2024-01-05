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
   int p; 
   int count;
} node;
int bfs(node arr[], int k) {
    // printf("%d ", k);
   arr[k].visited = 1;
   int siz = 1, flag = 1;
   ima(com,int,siz);
   com[0] = k; 
   f(i,siz) {
    f(j,arr[com[i]].edge) {
        if(!arr[arr[com[i]].adj[j]].visited) {
            arr[arr[com[i]].adj[j]].visited = 1;
            siz++;
            com = (int*) realloc(com,siz*sizeof(int));
            com[siz-1] = arr[com[i]].adj[j];
            arr[arr[com[i]].adj[j]].p = com[i];
        } else if( arr[com[i]].adj[j] != arr[com[i]].p) {
               int z = com[i], c = 1;
               while(z != 0) {
                  arr[arr[z].p].count = z;
                  z = arr[z].p;
               }
               z = arr[com[i]].adj[j];
               while(z != 0) {
                  if(arr[z].count != -1) {
                    break;
                  }  
                  c++;
                  z = arr[z].p;
               }
            while(1) { 
              c++;
              if(z == com[i]) break; 
              z = arr[z].count;   
            }; 
              printf("%d\n", c);
             z = arr[com[i]].adj[j];
            while(z != 0) {
              printf("%d ", z);
              z = arr[z].p;
              if(arr[z].count != -1) break;              
            }; 
              while(1) { 
              printf("%d ", z);
              if(z == com[i]) break; 
              z = arr[z].count;   
            }; 
            printf("%d ", arr[com[i]].adj[j]);
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
    graph[i].p = 0;
    graph[i].count = -1;
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
   if(k) printf("IMPOSSIBLE");
}