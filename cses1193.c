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
void traverse(int i, int j, char** mat,int** count) {
      int siz = 1, flag = 0;
      count[i][j] = 0;
      int* arr = (int*) malloc(siz*sizeof(int));
      arr[0] = (i*m) + j;
      f(kk,siz) {
        i = arr[kk] / m;
        j = arr[kk] % m;
      if(i > 0 &&  (mat[i-1][j] == '.' || mat[i-1][j] == 'A')) {
             count[i-1][j] = count[i][j] + 1;
            if(mat[i-1][j] == 'A') {
             flag = 1;
             mat[i-1][j] = 'D';
             i = i-1;   
                break;}
             mat[i-1][j] = 'D';
             siz++;
             arr = (int*) realloc(arr,siz*sizeof(int));
             arr[siz-1] = ((i-1)*m) + (j);
         } 
      if(i < n-1 &&  (mat[i+1][j] == '.' || mat[i+1][j] == 'A')) {
             count[i+1][j] = count[i][j] + 1;
              if(mat[i+1][j] == 'A') {
             flag = 1;
             mat[i+1][j] = 'U';
             i = i+1;   
                break;}
             mat[i+1][j] = 'U';
             siz++;
             arr = (int*) realloc(arr,siz*sizeof(int));
             arr[siz-1] = ((i+1)*m) + (j);
         } 
         if(j < m-1 &&  (mat[i][j+1] == '.' || mat[i][j+1] == 'A')) {
             count[i][j+1] = count[i][j] + 1;
             if(mat[i][j+1] == 'A') {
             flag = 1;
             mat[i][j+1] = 'L';  
             j = j+1; 
                break;}
             mat[i][j+1] = 'L';
             siz++;
             arr = (int*) realloc(arr,siz*sizeof(int));
             arr[siz-1] = (i*m) + (j+1);
         } 
         if(j > 0 &&  (mat[i][j-1] == '.' || mat[i][j-1] == 'A')) {
             count[i][j-1] = count[i][j] + 1;
             if(mat[i][j-1] == 'A') {
             flag = 1;
             mat[i][j-1] = 'R';
             j = j-1;   
                break;
                }
             mat[i][j-1] = 'R';
             siz++;
             arr = (int*) realloc(arr,siz*sizeof(int));
             arr[siz-1] = (i*m) + (j-1);
         } 
    }
    if(!flag) printf("NO\n");
    else {
         printf("YES\n%d\n", count[i][j]);
          while(mat[i][j] != 'B') {
            printf("%c", mat[i][j]);
            if(mat[i][j] == 'L') j -= 1;
            else if(mat[i][j] == 'R') j += 1;
            else if(mat[i][j] == 'D') i += 1;
            else if(mat[i][j] == 'U') i -= 1;
    }

}
}
int main() {
    sd(n);sd(m);
    ima(mat,char*,n);
    ima(count, int*, n);
    f(i,n){
         mat[i] = ma(char,m+1);
         count[i] = ma(int,m);
    }
    f(i,n) {
        scanf(" %s", mat[i]);
        f(j,m) count[i][j] = 1000001;
    }
    f(i,n) {
        f(j,m) {
            if(mat[i][j] == 'B') {
                traverse(i,j,mat,count);
                break;
            }
        }
    }
   return 0;
}