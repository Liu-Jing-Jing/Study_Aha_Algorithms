//
//  chapter4-2.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-30.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//
/*
int n, m, p, q, min=25000;
int a[51][51], book[51][51];

struct coord
{
    int x;
    int y;
}paths[2500];
int top;

void dfs(int x,int y, int step)
{
    int next[4][2] = {
        {0, 1}, // 向右走
        {1, 0}, // 向下走
        {0, -1}, // 向左走
        {-1, 0} // 向上走
    };
    
    int tx, ty, k;
    // 判断是否到达小哈和位置
    if(x== p && y==q)
    {
        // 更新最小值
        if(step<min)
        {
            min=step;
            for (int i = 1; i <= top; i++)
            {
                printf("path[%d] :(%d , %d)\n", i, paths[i].x, paths[i].y);
            }
        }
        return ; // 请注意这里的返回很重要
    }
    // 枚举4种走法
    for(k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        
        
        if(tx<1 || tx>n || ty<1 || ty>m)  continue;
        
        if(a[tx][ty]==0 && book [tx][ty]==0)
        {
            
            book[tx][ty]=1;
            top++; // 入栈
            paths[top].x = tx;
            paths[top].y = ty;
            
            dfs(tx, ty, step+1);
            
            book[tx][ty]=0; // 取消尝试
            top--;
        }
    }
    return;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    int i, j, startX, startY;
    printf("请输入该地图的行数和列数: ");
    scanf("%d %d", &n , &m);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("请输入小哼开始的位置:");
    scanf("%d %d", &startX, &startY);
    
    printf("请输入小哈所在的位置:");
    scanf("%d %d", &p, &q);
    
    book[startX][startY] = 1; // 标记起点已经在路径中， 防止以后重复走
    dfs(startX, startY, 0);
    printf("最短的路径：%d步\n", min);
    
    
    
    return 0;
}
 */
