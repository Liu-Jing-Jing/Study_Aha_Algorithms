//
//  chapter4-3.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-30.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//

#include<stdio.h>
struct note
{
    int x; // 横坐标
    int y; // 纵坐标
    int f; // 父亲在队列中的编号
    int s; // 第几步
};

/*
 地图
 0 0 1 0
 0 0 0 0
 0 0 1 0
 0 1 0 0
 0 0 0 1
 */

struct note queue[2501]; // 因为地图的大小不超过50*50, 因此队列扩展不会超过2500个
int a[51][51]={0}, book[51][51]={0};

// 定义一个用于表示走的方向的数组
int next[4][2] = {
    {0, 1}, // 向右走
    {1, 0}, // 向下走
    {0, -1}, // 向左走
    {-1, 0} // 向上走
};

/*
int head, tail;
int i, j, k, n, m, startX, startY, p, q, tx, ty, flag;
printf("请输入该地图的行数和列数:\n");
scanf("%d %d", &n , &m);
for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        scanf("%d", &a[i][j]);
    }
}

printf("请输入小哼开始的位置:\n");
scanf("%d %d", &startX, &startY);

printf("请输入小哈所在的位置:\n");
scanf("%d %d", &p, &q);

// initialize queue
head=1;
tail=1;
// 往队列插入迷宫入口坐标
queue[tail].x=startX;
queue[tail].y=startY;
queue[tail].f=0;
queue[tail].s=0;
tail++;
book[startX][startY]=1;
flag=0; // 用来标记是否到达目标点。0表示暂时没有到达
// 当队列不为空时循环
while(head<tail)
{
    // 枚举4种走法
    for(k=0;k<=3;k++)
    {
        tx=queue[head].x+next[k][0];
        ty=queue[head].y+next[k][1];
        // 判断是否越界
        if(tx<1 || tx>n || ty<1 || ty>m)  continue;
        // 判断是否是障碍物或者是否走过
        if(a[tx][ty]==0 && book [tx][ty]==0)
        {
            // 把这个点标记已经走过
            // 注意广度优先搜索和DFS不同，每个点只入队一次，不要将book数值还原
            book[tx][ty]=1;
            queue[tail].x=tx;
            queue[tail].y=ty;
            queue[tail].f=head;
            // 因为这个点是从head扩展出来，所以它的父亲是head，可以输出路径
            queue[tail].s = queue[head].s+1; // 步数是父亲的步数+1
            tail++;
        }
        if(tx==p && ty==q)
        {
            // 注意下面两句的顺序，一定不能写反！！！
            flag=1;
            break;
        }
    }
    if(flag==1) break;
    head++; // 注意这个地方千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
}
// 打印队列中末尾最后一个点(目标点)的步数
// 注意tail是指向队列队尾的下一个位置，所以需要-1
printf("%d步\n", queue[tail-1].s);
struct note current=queue[tail-1];
for (int i=current.s; i > 0; i--)
{
    printf("path:(%d)(%d)\n",current.x ,current.y);
    current = queue[current.f];
}

//    while(current.f > 0)
//    {
//        printf("path:(%d)(%d)\n",current.x ,current.y);
//        current = queue[current.f];
//    }
 */