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
int main() {
    tcase {
    int n;
    sd(n);
    ima(mat,int*,n+1);
    f(i,n+1) mat[i] = ma(int,n+1);
   for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        int a;sd(a);
        if(a != 32765)   mat[i][j] = a;
        else mat[i][j] = INF;
    }
     for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= n; j++) {
            for(int k = 1; k <= n; k++) {
        if(mat[j][k] > mat[j][] + mat[i][k]) {
            mat[k][j] = mat[i][j] + mat[i][k];
            mat[j][k] = mat[i][j] + mat[i][k];
        }
            }
        }
     }
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
        if(mat[i][j] >= INF)  printf("%d ", 32765);
        else  printf("%d ", mat[i][j]);
      }
      printf("\n");
      }
     f(i,n+1) free(mat[i]);
     free(mat);
    }
     return 0;
}