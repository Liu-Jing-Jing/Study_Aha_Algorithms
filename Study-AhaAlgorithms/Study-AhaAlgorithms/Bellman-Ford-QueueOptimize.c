//
//  Bellman-Ford-QueueOptimize.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-3-6.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "Bellman-Ford-QueueOptimize.h"
#include <stdio.h>
int bellman_ford_queue()
{
    int dis[10], k, n, m, i, j, u[10], v[10], w[10];
    int book[10], first[10], next[10];
    int que[101], head=1, tail=1;
    int inf = 99999999;
    j=0;
    // input n and m value
    scanf("%d %d", &n, &m);
    
    // initialization
    for(i=1;i<=n;i++)
    {
        dis[i] = inf;
    }
    
    dis[1] = 0;
    
    
    for(i=1;i<n;i++) book[i]=0;
    for(i=1;i<n;i++) first[i]=-1;
    
    // load sides
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        
        // 邻接表的核心代码, review
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    
    // 1号顶点入队
    que[tail]=1;
    tail++;
    book[1]=1; // mark - first point in the queue
    
    
    while(head<tail)
    {
        k=first[que[head]];
        while(k != -1)
        {
            if(dis[v[k]] > dis[u[k]] + w[k]) // 判断是否可以松弛
            {
                dis[v[k]] = dis[u[k]] + w[k];
                
                //book数组标记，可以优化
                if(book[v[k]]==0)
                {
                    // 入队操作
                    que[tail]=v[k];
                    tail++;
                    book[v[k]]=1;
                }
            }
            k= next[k];
        }
        
        // 出队
        book[que[head]] = 0;
        head++;
    }
    
    
    // print short path
    for(i=1;i<=n;i++)
    {
        printf("%d ", dis[i]);
    }
    getchar();
    getchar();
    return 0;
}
