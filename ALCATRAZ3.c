#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))	;
#define sd(i) scanf("%d", &i)
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a > b ? b : a;
#define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
#define endl printf("\n")
#define inf 1000000
int n,m,k,xx,yy;
int visited[100][100];
char mat[101][101];

int dfs( int x, int y) {
    int flag = -1;
    if(visited[x][y] && xx == x && yy == y) return 0;
    if(visited[x][y] || mat[x][y] == '*') return -1;
    visited[x][y] = 1;
     if(x > 0) flag = Max(flag, dfs(x-1,y));
     if (flag != -1 && flag+1>=k) return flag+1;
     if(x<n-1) flag = Max(flag, dfs(x+1,y));
     if (flag != -1 && flag+1>=k) return flag+1;
     if(y > 0) flag = Max(flag, dfs(x,y-1));
     if (flag != -1 && flag+1>=k) return flag+1;
     if(y < m-1) {
        flag = Max(flag, dfs(x,y+1));
        printf("%d\n", flag);
        }
     if (flag != -1 && flag+1>=k) return flag+1;
    visited[x][y] = 0;
    return flag < 0 ? (xx == x && yy == y ? 0 : -1)  : flag + 1;
    }  
int main() {
    scanf("%d %d %d %d %d",&n,&m,&k,&xx,&yy);
    xx--;yy--;
    f(i,n) scanf(" %s", mat[i]);
    int flag = dfs(xx,yy);
//     printf("%d\n", flag);
    if(flag >= k) printf("YES\n");
    else printf("NO\n");
   return 0;
}