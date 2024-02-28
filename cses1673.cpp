    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <math.h>
    #include <iostream>
    #include <queue>
    #define ll long long
    #define ull unsigned long long
    #define f(i, n) for(int i = 0; i < n; i++)
    #define ma(k, n) (k*) malloc(n*sizeof(k));
    #define ima(y, k, n) k* y = (k*) calloc((n),sizeof(k));
    #define sd(i) scanf("%d", &i)
    #define Max(a,b) a < b ? b : a;
    #define Min(a,b) a > b ? b : a;
    #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
    #define en printf("\n")
    #define inf 100000000000000
    using namespace std;
    int n,m;
    typedef struct  node
    {
       int edge;
       int* adj;
       int ultaedge;
       int* ultaadj;
       ll dis;
       int vis;
    } node;
    typedef struct edge {
      int a;
      int b;
      int w;
    } edge;
    node g[2504];
    edge edges[5001];
    void init() {
        f(i,n+1) {
            g[i].edge = 0;
            g[i].dis = inf;
            g[i].vis = 0;
            g[i].ultaedge = 0;
        }
    }
    void takeinp() {
    f(i,m) {
        int u,v,w;
        sd(u);sd(v);sd(w);
        edges[i].a = u;
        edges[i].b = v;
        edges[i].w = -1*w;
        g[u].edge++;
        g[u].adj = (int*) realloc(g[u].adj, sizeof(int)*g[u].edge);
        g[u].adj[g[u].edge-1] = v;
        g[v].ultaedge++;
        g[v].ultaadj = (int*) realloc(g[v].ultaadj, sizeof(int)*g[v].ultaedge);
        g[v].ultaadj[g[v].ultaedge-1] = u;
    }
    } 
  void dfs(int i) {
    g[i].vis = 1;
    f(j,g[i].edge) {
        int k = g[i].adj[j];
        if(g[k].vis == 1) continue;
        else if(g[k].vis == 0)  dfs(k);
    }
    }
  void ultadfs(int i) {
    g[i].vis |= 2;
    f(j,g[i].ultaedge) {
        int k = g[i].ultaadj[j];
        if(g[k].vis & (1<<1)) continue;
        else  ultadfs(k);
    }
    }
int bellman() {
  int flag = 0;
  for(int i = 0; i <=n;i++) {
    for(int j = 0; j < m;j++) {
      int u = edges[j].a;
      int v = edges[j].b;
      ll w = (ll)edges[j].w;
      if((g[u].vis & g[v].vis) != 3) continue;
      else {
        // printf("%d %d\n",u,v);
        // printf("%lld %lld\n",g[u].dis,g[v].dis);
        if(g[v].dis > g[u].dis + w) {
          g[v].dis = g[u].dis + w;
          if(i==n) flag = 1;
          if(flag) break;
        }
      }
    }
  }
  return !flag;
 }
 int main() {
    sd(n);sd(m);
    init();
    takeinp();
    g[1].dis = 0;
     dfs(1);
     ultadfs(n);
    //  f(i,n+1) printf("%d\n", g[i].vis);
     int bel = bellman();
     if(!bel) printf("-1\n");
     else printf("%lld\n", -1*g[n].dis);
    
 }