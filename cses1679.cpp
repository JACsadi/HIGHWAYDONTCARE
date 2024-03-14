  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <stdbool.h>
  #include <iostream> 
  #include <stack>
  #include <queue>
  #define ll long long
  #define f(i, n) for (int i = 0; i < n; i++)
  #define ma(k, n) (k*) malloc(n*sizeof(k))
  #define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
  #define sd(i) scanf("%d", &i)
  using namespace std;
  int n,m;
  typedef struct course {
    int dep;
    int edge;
    int vis;
    int* adj;
  } course;
  course c[100001];
  queue<int> q;
  void sala(int s) {
    q.push(s);
    c[s].vis = 1;
    f(i,c[s].edge) {
        int next = c[s].adj[i];
        c[next].dep--;
        if(c[next].dep == 0) sala(next);
    }
  }
  int main() {
    int n,m;
    sd(n);sd(m);
    f(i,n+1) {
        c[i].dep = 0;
        c[i].edge = 0;
        c[i].vis = 0;
    }
    f(i,m) {
        int u,v;
        sd(u);sd(v);
        c[u].edge++;
        c[v].dep++;
        c[u].adj = (int*) realloc(c[u].adj, c[u].edge*sizeof(int));
        c[u].adj[c[u].edge-1] = v;
    }
    f(i,n+1) {
        if(i==0) continue;
        if(!c[i].vis && c[i].dep == 0) sala(i);
    }
    if(q.size() == n) {
        while (!q.empty()) 
        {
            printf("%d ", q.front());
            q.pop();
        }
    } else printf("IMPOSSIBLE");
    return 0;
  }