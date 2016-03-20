//
//  Bellman-Ford.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-3-6.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "Bellman-Ford.h"

void bellman_Ford()
{
    int dis[10], k, i, n, m, u[10], v[10], w[10], check, flag;
    int inf = 99999999;
    
    scanf("%d %d", &n, &m);
    
    // load sides
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    
    // initialization
    for(i=1;i<=n;i++)
    {
        dis[i] = inf;
    }
    
    dis[1] = 0;
    
    
    
    
    // Bellman-Ford core
    for(k=1;k<=n-1;k++)
    {
        check = 0;
        
        // 进行一轮边的松弛操作
        for(i=1;i<=m;i++)
        {
            if(dis[v[i]]>(dis[u[i]]+ w[i]) && w[i]<inf)
            {
                dis[v[i]] = dis[u[i]]+ w[i];
                check = 1;
            }
        }
        
        if(check == 0) break;
    }
    
    //检测是否是负权回路
    flag = 0;
    for(i=1;i<=m;i++)
    {
        if(dis[v[i]] > dis[u[i]]+ w[i]) flag=1;	
    }
    
    if(flag==1) printf("含有负权回路\n");
    else
    {
        // print
        for(i=1;i<=n;i++)
        {
            printf("%d ", dis[i]);
        }
    }
    
    
    getchar();
    getchar();
}


/*
 int x=-99, i=1;
 while(x<100)
 {
 printf("%d打印%d\n", i++,(x>0?100-x:100+x));
 x++;
 }
 */