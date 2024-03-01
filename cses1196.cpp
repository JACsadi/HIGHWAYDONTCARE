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
    int n,m,k;
    void merge(ll *arr, int l, int m, int r) {
    if(l != r) {
        ll L[m - l + 1], R[r - m];
        for(int i = l; i <= m; i++) L[i-l] = arr[i];
        for(int i = m + 1; i <= r; i++) R[i - m - 1] = arr[i];
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j] = L[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j] = R[j];
                 j++;
            } else if(L[i] < R[j]){
                arr[l+i+j] = L[i];
                 i++;
            } else {
                 arr[l+i+j] = R[j];
                 j++;
            }
        } 
    }
}
    void sortttt(ll *arr, int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr, l ,mid);
        sortttt(arr, mid + 1, r);
    }
    merge(arr,l,mid,r);
}
    typedef struct  node
    {
       int edge;
       int* adj;
       int* w;
       ll* dis;
       int v;
    } node;
    node g[100001];
    void init() {
        f(i,n+1) {
            g[i].edge = 0;
            g[i].dis = ma(ll,k);  
            f(j,k) g[i].dis[j] = inf;
            g[i].v = 0;
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
    }
    }
  void ds() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    g[1].dis[0] = 0;
    pq.push({(ll)0,1});
    while(!pq.empty()) {
        pair<ll,int> top = pq.top();
        pq.pop();
        int i = top.second;
        ll val = top.first;
        g[i].v++;
        if(g[i].v > k) continue;
        f(j,g[i].edge) {
            int nextnode = g[i].adj[j];
            ll w = (ll)g[i].w[j];
            if(g[nextnode].dis[k-1] > val + w) {
                g[nextnode].dis[k-1] = val + w;
                sortttt(g[nextnode].dis,0,k-1);
                pq.push({val+w,nextnode});
            }   
        }
  }
  }
 int main() {
    sd(n);sd(m);sd(k);
    init();
    takeinp();
    ds();
   f(i,k) printf("%lld ", g[n].dis[i]);

 }