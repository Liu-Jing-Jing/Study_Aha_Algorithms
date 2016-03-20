//
//  Floyd-Warshall.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-3-6.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "Floyd-Warshall.h"

#include <stdio.h>

int main_test()
{
    int e[10][10], k, i, j, n, m, t1, t2, t3;
    int inf = 99999999;
    
    scanf("%d %d", &n, &m);
    
    
    // initialization
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                e[i][j]=0;
            }
            else
            {
                e[i][j]=inf;
            }
        }
    }
    
    
    // load sides
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }
    
    // Floyd core
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(e[i][j]>e[i][k]+e[k][j] && e[i][k]<inf && e[k][j]<inf)
                    e[i][j]=e[i][k]+e[k][j];
    
    
    // print
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%10d", e[i][j]);
        }
        
        printf("\n");
    }
    
    getchar();
    getchar();
    return 0;
}