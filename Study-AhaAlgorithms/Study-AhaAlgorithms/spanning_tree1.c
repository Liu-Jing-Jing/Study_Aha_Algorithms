//
//  spanning_tree1.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-3-20.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "spanning_tree1.h"
// kruskal
struct edge
{
    int u;
    int v;
    int w;
};
// 为了方便排序， 这里创建一个结构体来存储边的关系

struct edge e[10];
int n, m;
int f[20]={0}, sum=0, count=0;


void quickSort1(int left, int right)
{
    int i, j;
    struct edge t;
    if(left>right) return;
    
    i = left;
    j = right;
    
    while(i != j)
    {
        // 重要的是，从右边先开始找、
        while(e[j].w >= e[left].w && i<j) j--;
        
        // 再从左边开始找
        while(e[i].w <= e[left].w && i<j) i++;
        
        
        //swap
        if(i<j)
        {
            t=e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    
    // 最终将基准数归位, 将left与i互换
    t = e[left];
    e[left]=e[i];
    e[i] = t;
    
    quickSort1(left, i-1);
    quickSort1(i+1, right);
    return;
}

// 并查集算法，寻找祖先的函数
int getf(int v)
{
    if(f[v] == v)
    {
        return v;
    }
    else
    {
        // 路径压缩
        f[v] = getf(f[v]);
        return f[v];
    }
}
// 并查集合并两个子集合的函数
int merge(int v, int u)
{
    int t1, t2;
    t1=getf(v);
    t2=getf(u);
    
    if(t1 != t2) // 判断两个点是否在同一个集合中
    {
        f[t2] = t1;
        return 1;
    }
    
    return 0;
}

int spanningTree1()
{
    int i;
    
    scanf("%d %d", &n, &m);
    
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    
    
    quickSort1(1, m); // 按照权值从小到大对边快速排序
    
    // 并查集初始化
    for(i=1;i<=n;i++)
    {
        f[i] = i;
    }
    
    
    // Kruskal 算法核心部分
    for(i=1;i<m;i++)
    {
        if(merge(e[i].u, e[i].v))
        {
            count++;
            sum=sum+e[i].w;
        }
        
        if(count == n-1) break; //直到选用了N-1条边之后退出循环
    }
    
    printf("%d", sum);
    
    getchar();
    getchar();
    return 0;
}
