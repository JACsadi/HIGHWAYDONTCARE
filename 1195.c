#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf("%d", &i)
int n,m;
char str[2505];
int siz = 0;
int dfs(int x1,int y1,int x2,int y2, int** arr) {
    //  printf("%d %d %d %d\n", x1,y1,x2,y2);
    int flag = 1;
    arr[y1][x1] = 1; 
    if(x1 == x2 && y1 == y2) {
       f(i,n) f(j,m) if(arr[i][j] == 0) {
        flag = 0; break;
       }
       if(flag) printf("YES\n");
    } else {
       flag = 0;
       if(y1 > 0 && !arr[y1-1][x1]){ 
         flag = dfs(x1,y1-1,x2,y2,arr);
         if(flag) {
            str[siz] = 'U';
            siz++;
         }
       }
       if(!flag && x1 > 0 && !arr[y1][x1-1]) {flag = dfs(x1-1,y1,x2,y2,arr);
        if(flag) {
            str[siz] = 'L';
            siz++;
         }
       }
       if(!flag && y1 < n-1 && !arr[y1+1][x1]) {flag = dfs(x1,y1+1,x2,y2,arr);
        if(flag) {
            str[siz] = 'D';
            siz++;
         }
       }
       if(!flag && x1 < m-1 && !arr[y1][x1+1]){ flag = dfs(x1+1,y1,x2,y2,arr);
        if(flag) {
            str[siz] = 'R';
            siz++;
         }}
    }
    if(flag) arr[y1][x1] = 0;
    return flag;
}
int main() {
 int t; sd(t);
 while(t--) {
 sd(n);sd(m);
 int y1,x1,y2,x2;
 scanf("%d %d %d %d", &y1,&x1,&y2,&x2);
 x1--;x2--;y2--;y1--;
//  printf("%d %d %d %d\n", x1,y1,x2,y2);
 ima(arr,int*,n);
 f(i,n) arr[i] = ma(int,m);
 f(i,n) f(j,m) arr[i][j] = 0;
//  f(i,n) {
//      f(j,m) printf("%d", arr[i][j]);
//      printf("\n");
//  }
 int flag = dfs(x1,y1,x2,y2,arr);
 if(flag){
   f(i,siz) printf("%c", str[i]);
 }
 else printf("No\n");
}
return 0;
}
