#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf("%d", &i)
// this was done with normal approach , with no use of anything graph related
//  int main() {
//     int t;
//     sd(t);
//     while(t--) {
//         int n;
//         sd(n);
//         int flag = -1;
//         ima(arr,int,n);
//         f(i,n) scanf("%d", &arr[i]);
//         if(arr[0] == 1) flag = n+1;
//         else {
//         f(i,n) {
//          if(arr[i] == 0 && (i == n-1 || arr[i+1] == 1)) {
//             flag = i;
//             break;
//          }
//         }
//         }
//         if(flag == -1) printf("-1\n");
//         else  {
//            if(flag == n+1) printf("%d ", flag);
//         f(i,n) { 
//             printf("%d ", i+1);
//             if(flag == i) printf("%d ", n+1);
//         }
//         printf("\n");
//         }
        
//     }
//     return 0;
//  }
//now i'll try to do it with dfs
int visited[10001] = {0};
int dfs(int** arr,int* last, int* ans, int node, int count, int n) {
   visited[node] = 1;
   count++;
//   printf("%d %d %d\n", node,count, n);
   int d = count;
   if(count < n+1) {
   if(n != node) {
    for(int i = 0; i <  2; i++) {
        if(i == 0 && arr[node][i] && !visited[node+1]) {
           d = dfs(arr,last,ans,node+1,count,n);
           if(d == n+1) break;
        } else if(i == 1 && arr[node][i] && !visited[n]) {
           d = dfs(arr,last,ans,n,count,n);
           if(d == n+1) break;
        }
    }
   } else {
       for(int i = count-1; i < n; i++) {
        if(last[i]  && !visited[i]) {
            d = dfs(arr,last,ans,i,count,n);
           if(d == n+1) break; 
        }
       }
   }
   }
   visited[node] = 0;
   if(d == n+1) ans[count-1] = node+1;
   return d;
}
int main() {
     int t;
    sd(t);
    while(t--) {
        int n;
        sd(n);
        ima(mat, int*, n);
        ima(ans,int,2*n);
        int* last = (int*) calloc(n, sizeof(int));
        f(i, n) {
                mat[i] = (int*) calloc(2, sizeof(int));
                if(n-1 != i) mat[i][0] = 1;
        
        }
        f(i,n) {
            int a; sd(a);
            if(a) last[i] = 1;
            else mat[i][1] = 1; 
        }
        int d;
        if(last[0]) {
          visited[n] = 1;
          ans[0] = n+1;
          d = dfs(mat,last,ans,0,1,n); 
          visited[n] = 0;
        } else  d = dfs(mat,last,ans,0,0,n);
        if(d != n+1) printf("-1");
        else f(i,n+1) printf("%d ", ans[i]);
        printf("\n");
         free(last);
        free(ans);
        f(i,n) free(mat[i]);
        free(mat);
    }
    return 0;
}