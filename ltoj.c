#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#define ll unsigned long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc((n)*sizeof(k))
#define ima(y, k, n) k* y = (k*) malloc((n)*sizeof(k))
#define sd(i) scanf("%d", &i)
#define INF (INT_MAX / 2)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
int n,m, ans;
typedef struct node {
   int edge;
   int* adj;
   bool visited; 
   int* val;
} node;
int dfs(node arr[], int index, int value) {
    arr[index].visited = 1;
    // printf("%d\n", index);
    int max1= 0, max2=0;
    f(i,arr[index].edge) {
        if(!arr[arr[index].adj[i]].visited) {
            int k = dfs(arr,arr[index].adj[i], arr[index].val[i]);
            if(k >= max1) {
                max2 = max1;
                max1 = k;
            } else if(k > max2) max2 = k; 
    }
}
ans = (max1+max2) > ans ? max1+max2 : ans;
return max1+value;
}
int main() {
 tcase {
    ans = 0;
  sd(n);
  node graph[n+1];
  f(i,n+1) {
    graph[i].edge = 0;
    graph[i].adj =  ma(int,0);
    graph[i].visited = 0;
     graph[i].val =  ma(int,0);
  }
  f(i,n-1) {
    int a,b,c;
    sd(a);sd(b),sd(c);
    graph[a].edge++;
    graph[a].adj = (int*) realloc(graph[a].adj, graph[a].edge*sizeof(int));
    graph[a].adj[graph[a].edge - 1] = b;
    graph[a].val = (int*) realloc(graph[a].val, graph[a].edge*sizeof(int));
    graph[a].val[graph[a].edge - 1] = c;
    graph[b].edge++;
    graph[b].adj = (int*) realloc(graph[b].adj, graph[b].edge*sizeof(int));
    graph[b].adj[graph[b].edge - 1] = a;
    graph[b].val = (int*) realloc(graph[b].val, graph[b].edge*sizeof(int));
    graph[b].val[graph[b].edge - 1] = c;
  }
  int a = dfs(graph, 0, 0);
  printf("Case %d: %d\n", casee, ans);
 }
 return 0;
}