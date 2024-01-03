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
int n,m;
void traverse(int i, int j, char** mat) {
      mat[i][j] = '#';
      if(j < m-1 && mat[i][j+1] == '.')  traverse(i,j+1,mat);
      if(i < n-1 && mat[i+1][j] == '.')  traverse(i+1,j,mat);
      if(j != 0 && mat[i][j-1] == '.')   traverse(i,j-1,mat);
      if(i != 0 && mat[i-1][j] == '.')   traverse(i-1,j,mat);
}
int main() {
    sd(n);sd(m);
    ima(mat,char*,n);
    f(i,n) mat[i] = ma(char,m+1);
    f(i,n) scanf(" %s", mat[i]);
    int ans = 0;
    f(i,n) {
        f(j,m) {
            if(mat[i][j] == '.') {
                traverse(i,j,mat);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}