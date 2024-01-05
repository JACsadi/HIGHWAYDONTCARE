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
int traverse(int i, int j, char** mat,int** count) {
 int flag = 1;
 int siz = 1;
 ima(temp,int,siz);
 temp[0] = (i*m) + j;
f(kk, siz) {
        i = temp[kk] / m;
        j = temp[kk] % m;
 if(i == 0 || i == n-1 || j == 0 || j == m-1) {
    flag = 0;
    printf("YES\n");
    printf("%d\n", count[i][j]);
    char str[count[i][j] + 2];
             int ai = i, aj = j, k = 0;
             while(mat[ai][aj] != 'A') {
                str[k] = mat[ai][aj];
                k++;
                if(mat[ai][aj] == 'L') aj++;
                else if(mat[ai][aj] == 'R') aj--;
                else if(mat[ai][aj] == 'U') ai++;
                else if(mat[ai][aj] == 'D') ai--;
             }
    f(kk,count[i][j]) printf("%c", str[count[i][j] -1 - kk]);
    break;
 }
  if(flag) { 
    if(i > 0 && mat[i-1][j] != '#' && count[i-1][j] > count[i][j] +1 ) {
        count[i-1][j] = count[i][j] +1;
        mat[i-1][j] = 'U';
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i-1)*m + j;
  }
   }
   if(flag) { 
   if(i < n-1 && mat[i+1][j] != '#' && count[i+1][j] > count[i][j] +1 ) {
        count[i+1][j] = count[i][j] +1;
        mat[i+1][j] = 'D';
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i+1)*m + j;    }
   }
   if(flag) { 
   if(j > 0 && mat[i][j-1] != '#' && count[i][j-1] > count[i][j] +1 ) {
        count[i][j-1] = count[i][j] +1;
        mat[i][j-1] = 'L';
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i)*m + j-1;    }
   }
   if(flag) { 
   if(j < m-1 && mat[i][j+1] != '#' && count[i][j+1] > count[i][j] +1 ) {
        count[i][j+1] = count[i][j] +1;
         mat[i][j+1] = 'R';
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i)*m + j+1;
   }
   }
}
   return flag;
}
void traversem(int i, int j, char** mat,int** count) {
    mat[i][j] = 'K';
    int siz = 1;
    ima(temp,int,siz);
    temp[0] = (i*m) + j;
    f(kk, siz) {
        i = temp[kk] / m;
        j = temp[kk] % m;
      if(i > 0 && mat[i-1][j] != '#' && count[i-1][j] > count[i][j] +1 ) {
        count[i-1][j] = count[i][j] +1;
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i-1)*m + j;
     } 
   if(j > 0 && mat[i][j-1] != '#' && count[i][j-1] > count[i][j] +1 ) {
        count[i][j-1] = count[i][j] +1;
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i)*m + j-1;
   }
    if(i < n-1 && mat[i+1][j] != '#' && count[i+1][j] > count[i][j] +1 ) {
        count[i+1][j] = count[i][j] +1;
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i+1)*m + j;
   } 
   if(j < m-1 && mat[i][j+1] != '#' && count[i][j+1] > count[i][j] +1 ) {
        count[i][j+1] = count[i][j] +1;
        siz++;
        temp = (int*) realloc(temp, siz*sizeof(int));
        temp[siz-1] = (i)*m + j+1;
   }  
    
    if(j < m-1 && mat[i][j+1] == 'M')  traversem(i,j+1,mat,count);
    if(i < n-1 && mat[i+1][j] == 'M')  traversem(i+1,j,mat,count);
    if(j > 0 && mat[i][j+1] == 'M')  traversem(i,j-1,mat,count);
    if(i > 0 && mat[i][j+1] == 'M')  traversem(i-1,j,mat,count);
    }
    free(temp);
}
int main() {
    sd(n);sd(m);
    ima(mat,char*,n);
    ima(count, int*, n);
    f(i,n){
         mat[i] = ma(char,m+1);
         count[i] = ma(int,m);
    }
     int ai = 0, aj = 0;
    f(i,n) {
        scanf(" %s", mat[i]);
        f(j,m) {
            if(mat[i][j] == 'M' || mat[i][j] == 'A' ) {
            count[i][j] = 0;
             if(mat[i][j] == 'A') {
                ai = i;
                aj = j;
             }
            } else {
                count[i][j] = 10000001;
            }
        }
    }
//    printf("%d %d %c\n", ai, aj, mat[ai][aj]);
    f(i,n) {
        f(j,m) {
            if(mat[i][j] == 'M') {
                traversem(i,j,mat,count);
              
            } 
        }
    }
//    printf("%d %d %c\n", ai, aj, mat[ai][aj]);
   int flag = traverse(ai,aj,mat,count);
   if(flag) printf("NO");
   return 0;
}