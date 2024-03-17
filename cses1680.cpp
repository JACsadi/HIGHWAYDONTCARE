 #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <stdbool.h>
  #include <iostream> 
  #include <stack>
  #define ll long long
  #define f(i, n) for (int i = 0; i < n; i++)
  #define ma(k, n) (k*) malloc(n*sizeof(k))
  #define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
  #define sd(i) scanf("%d", &i)
  #define Max(a,b) ((a) < (b) ? (b) : (a))
  #define Min(a,b) ((a) > (b) ? (b) : (a))
  #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
  using namespace std;
  int n,m;
  typedef struct node {
    int edge;
    int* adj;    
    int vis;
    int dis;
    int nex;
  } node;
  node g[100005]; 
  void dfs(int s) {
    g[s].vis = 1;
    if(s == n) {
      g[s].dis = 1;
      return;
    }
    f(i,g[s].edge) {
      int next = g[s].adj[i];
      if(!g[next].vis) dfs(next);
      if(g[next].dis) {
        if(g[s].dis < g[next].dis+1) {
          g[s].dis =  g[next].dis+1;
          g[s].nex = next;
        }
      }
    }
  }
  int main() {
    sd(n);sd(m);
    f(i,n+1) {
      g[i].edge = 0;
      g[i].vis = 0;
      g[i].dis = 0;
      g[i].nex = 0;
    }
    f(i,m) {
      int a,b;
      sd(a);sd(b);
      g[a].edge++;
      g[a].adj = (int*) realloc(g[a].adj, g[a].edge*sizeof(int));
      g[a].adj[g[a].edge - 1] = b;
    }
    dfs(1);
    if(g[1].dis > 0) {
    printf("%d\n", g[1].dis);
    int i = 1;
   while(i != 0) {
    printf("%d ", i);
    i = g[i].nex;
   }
    } else printf("IMPOSSIBLE");
  }