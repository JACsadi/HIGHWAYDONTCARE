    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <math.h>
    #include <iostream>
    #include <queue>
    #include <stack>
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
       ll dis;
       int p;
       int v;
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
            g[i].p = -1;
            g[i].v = 0;
        }
    }
    void takeinp() {
    f(i,m) {
        int u,v,w;
        sd(u);sd(v);sd(w);
        edges[i].a = u;
        edges[i].b = v;
        edges[i].w = w;
        g[u].edge++;
        g[u].adj = (int*) realloc(g[u].adj, sizeof(int)*g[u].edge);
        g[u].adj[g[u].edge-1] = v;
    }
    } 

int bellman() {
  stack<int> st;
  int flag = 0;
  for(int i = 0; i <=n;i++) {
    for(int j = 0; j < m;j++) {
      int u = edges[j].a;
      int v = edges[j].b;
      ll w = (ll)edges[j].w;
        // printf("%d %d\n",u,v);
        // printf("%lld %lld\n",g[u].dis,g[v].dis);
        if(g[v].dis > g[u].dis + w) {
          g[v].dis = g[u].dis + w;
          g[v].p = u;
          if(i==n){
             flag = 1;
             printf("YES\n");
             int last = v;
             while(1) {
                // printf("%d ", last);
                st.push(last);
                if(g[last].v)  break;
                else {
                g[last].v = 1;
                last = g[last].p;
                }
             }
             while(!st.empty()) {
                printf("%d ", st.top());
                st.pop();
             }
             }
          if(flag) break;
        }
    }
  }
  return flag;
 }
 int main() {
    sd(n);sd(m);
    init();
    takeinp();
    g[1].dis = 0;
    //  f(i,n+1) printf("%d\n", g[i].vis);
     int bel = bellman();
     if(!bel) printf("NO\n");
 }