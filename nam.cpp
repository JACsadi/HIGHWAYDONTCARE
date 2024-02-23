#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;




int main()
{
    
    int m,n,x,y;
    scanf("%d %d",&n,&m);
    int dpnd[n+1],ed[n+1],arr[n], index=0;
    int** adj= (int**)malloc((n+1)*sizeof(int*));
      for(int i=0;i<n+1;i++)
    {
        dpnd[i]=0;
        ed[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        ed[x]++;
        dpnd[y]++;
        adj[x]=(int*)realloc(adj[x],ed[x]*sizeof(int));
        adj[x][ed[x]-1]=y;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
     for(int i=1;i<n+1;i++)
    {
        if(!dpnd[i])
        {
            pq.push(i);
        }
    }
        while(!pq.empty())
        {
            int top=pq.top();
            arr[index]=top;
            index++;
             pq.pop();
            while(ed[top])
            {
                    ed[top]--;
                    dpnd[adj[top][ed[top]]]--;
                   if(!dpnd[adj[top][ed[top]]])  pq.push(adj[top][ed[top]]);
                   
            }
        }

    //    printf("%d ",index);
    if(index==n){
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    else { printf("Sandro fails.");}
    
}