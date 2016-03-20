//
//  chapter5.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-1-6.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "chapter5.h"


/* 广度优先实现图的遍历
 int i, j, n, m, a, b, cur, book[101] = {0}, e[101][101];
 int que[10001], head, tail;
 scanf("%d %d", &n, &m);
 
 
 // 初始化二维矩阵
 for(i = 1; i <= n; i++)
 {
 for(j = 0; i <= n; i++)
 {
 if(i == j)
 {
 e[i][j] = 0;
 }
 else
 {
 e[i][j] = PositiveInfinity;
 }
 }
 }
 
 
 for(i = 1; i <= m; i++)
 {
 scanf("%d %d", &a, &b);
 e[a][b] = 1;
 e[b][a] = 1;
 }
 
 // init queue
 head = 1;
 tail = 1;
 
 que[tail] = 1;
 tail++;
 book[1] = 1;
 
 // 当队列不为空的时候循环
 while (head < tail)
 {
 cur = que[head];
 for(i = 1; i <= n; i++)
 {
 if (e[cur][i] == 1 && book[i] == 0)
 {
 que[tail] = i;
 tail++;
 book[i] = 1;
 }
 
 if(tail > n) break;
 }
 
 head++;
 }
 
 
 // output result
 for(i = 1; i < tail; i++)
 {
 printf("%d ", que[i]);
 }
 
 
 */

void dfs(int cur) // cur是当前所在的定点的编号
{
    int i;
    printf("%d ", cur);
    sum++; // 每访问一个顶点，sum就加1
    
    if (sum == n) return; // 所有的定点都已经访问过则直接退出
    for(i = 1; i <= n; i++)
    {
        //
        if (e[cur][i] == 1 && book[i] == 0)
        {
            book[i] = 1;
            dfs(i);
        }
    }
    
    return;
}

/*
// 函数的使用
int main(int argc, const char * argv[])
{
    // insert code here...
    
    int i, j, m, a, b;
    scanf("%d %d", &n, &m);
    
    // 初始化二维矩阵
    for(i = 1; i <= n; i++)
    {
        for(j = 0; i <= n; i++)
        {
            if(i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = PositiveInfinity;
            }
        }
    }
    
    
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    book[1] = 1;
    dfs(1);
    
    return 0;
}
*/