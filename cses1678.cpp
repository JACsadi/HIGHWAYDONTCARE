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
  using namespace std;
  int n,m;
  typedef struct node {
    int edge;
    int* adj;    
    int vis;
    int p; 
    int count;
  } node;
  node g[100005]; 
  stack<int> q;
  int last;
  int dfs(int s) {
    g[s].vis = 2;
    int f = 0;
    f(i,g[s].edge) {
      int next = g[s].adj[i];
      if(g[next].vis == 2) {
        f = 1;
        q.push(next);
        q.push(s);
        last = next;
        return f;
      } else if(g[next].vis==0) {
        f = dfs(next);
        if(f == 1) {
          q.push(s);
          if(s == last) return 2;
          return f;
        } else if(f==2) return 2;
      }
    }
    g[s].vis = 1;
    return f;
  }
  int main() {
    sd(n);sd(m);
    f(i,n+1) {
      g[i].edge = 0;
      g[i].adj = ma(int,0);
      g[i].vis = 0;
      g[i].p = 0;
      g[i].count = -1;
    }
    f(i,m) {
      int a,b;
      sd(a);sd(b);
      g[a].edge++;
      g[a].adj = (int*) realloc(g[a].adj, g[a].edge*sizeof(int));
      g[a].adj[g[a].edge - 1] = b;
    }
    int k = 1;
    f(i,n+1) {
      if(!g[i].vis) {
        k = dfs(i);
        if(k) {
          printf("%d\n", q.size());
          while (!q.empty()) {
            printf("%d ", q.top());
            q.pop();
          }
          break;
          }
      }
    }
    if(!k) printf("IMPOSSIBLE");
    return 0;
  }