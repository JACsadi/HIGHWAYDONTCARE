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
    #define inf 10000000000000000
    using namespace std;
    int n,m;
    typedef struct  node
    {
       int edge;
       int* adj;
       int* w;
       ll dis;
    } node;
    node g[100001];
    void init() {
        f(i,n+1) {
            g[i].edge = 0;
            g[i].dis = inf;
        }
    }
    void takeinp() {
    f(i,m) {
        int u,v,w;
        sd(u);sd(v);sd(w);
        g[u].edge++;
        g[u].adj = (int*) realloc(g[u].adj, sizeof(int)*g[u].edge);
        g[u].adj[g[u].edge-1] = v;
        g[u].w = (int*) realloc(g[u].w, sizeof(int)*g[u].edge);
        g[u].w[g[u].edge-1] = w;
        // g[v].edge++;
        // g[v].adj = (int*) realloc(g[v].adj, sizeof(int)*g[v].edge);
        // g[v].adj[g[v].edge-1] = u;
        // g[v].w = (int*) realloc(g[v].w, sizeof(int)*g[v].edge);
        // g[v].w[g[v].edge-1] = w;
    }
    }
  void ds() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({(ll)0,1});
    while(!pq.empty()) {
        pair<ll,int> top = pq.top();
        pq.pop();
        int i = top.second;
        ll val = top.first;
        if(g[i].dis > val) {
            g[i].dis = val;
            f(j,g[i].edge) {
              int nextnod = g[i].adj[j];
              ll nextval = (ll)g[i].w[j] + (ll)g[i].dis;
              if(g[nextnod].dis > nextval) pq.push({nextval,nextnod});
            }
        }
    }
  }
 int main() {
    sd(n);sd(m);
    init();
    takeinp();
    ds();
    f(i,n+1) {
        if(i==0) continue;
        printf("%lld ", g[i].dis);
    } 
 }