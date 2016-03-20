//
//  spanning_tree3.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 16-3-20.
//  Copyright (c) 2016年 TechLewis. All rights reserved.
//

#include "spanning_tree3.h"
/*
int dis[7], book[7]={0};
int h[7], pos[7], size;

// swap func
void swapCh8(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    
    // update pos[]
    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]]=t;
    return;
}

//
void siftdownCh8(int i)
{
    int t, flag=0;
    
    
    while(i*2<=size && flag==0)
    {
        if(dis[h[i]] > dis[h[i*2]])
        {
            t = i*2;
        }
        else
        {
            t = i;
        }
        
        
        
        if((i*2+1) <= size)
        {
            if(dis[h[t]] > dis[h[i*2+1]])
                t = i*2+1;
        }
        
        if(t != i)
        {
            // swap
            swapCh8(t ,i);
            i=t;
        }
        else
        {
            flag = 1;
        }
    }
    
    return;
}

void siftup_ch8(int i)
{
    int flag=0;
    if(i == 1) return;
    
    while(i!=1 && flag==0)
    {
        if(dis[h[i]] < dis[h[i/2]])
        {
            swapCh8(i, i/2);
        }
        else
        {
            flag=1;
        }
        
        i=i/2;
    }
    
    return;
}
 */
// Function: create the heap
/*
 void create()
 {
	int i;
 //从最后一个非叶节点 到 第一个节点依次siftdown
	for(i=n/2;i>=1;i--)
 {
 siftdown(i);
 }
 
 return;
 }
 */


/*
int pop()
{
    int t;
    t=h[1];
    pos[t]=0;
    h[1]=h[size];
    pos[h[1]]=1;
    size--;
    siftdownCh8(1);
    return t;
}
 */

int spanningTree3()
{
    /*
    int n, m, i, j, k;
    //u v w和next数组的大小要根据实际情况设置，此图为无向图，要比2*m大1
    int u[19], v[19], w[19], first[7], next[19];
    int inf=99999999;
    int count = 0, sum = 0;
    
    // init
    scanf("%d %d", &n, &m);
    
    // load sides
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    
    for(i=m+1;i<=2*m;i++)
    {
        u[i] = v[i-m];
        v[i] = u[i-m];
        w[i] = w[i-m];
    }
    
    // 邻接表
    for(i=1;i<=n;i++) first[i]= -1;
    for(i=1;i<=2*m;i++)
    {
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    
    // init book[]
    for(i=1;i<=n;i++) book[i]= 0;
    // Prim algo core code
    // firt point add to the tree
    book[1]=1;
    count++;
    
    // init dis[]
    dis[1]=0;
    for(i=2;i<=n;i++) dis[i]=inf;
    k=first[1];
    while(k != -1)
    {
        dis[v[k]]=w[k];
        k=next[k];
    }
    
    //init heap
    size = n;
    for(i=1;i<=size;i++)
    {
        h[i]=i;
        pos[i]=i;
        
    }
    for(i=size/2;i>=1;i--)
    {
        siftdown_ch8(i);
    }
    pop();
    
    
    while(count<n)
    {
        j=pop();
        book[j]=1;
        count++;
        sum=sum+dis[j];
        
        
        //
        k=first[j];
        
        while(k != -1)
        {
            if(book[v[k]]==0 && dis[v[k]]>w[k])
            {
                dis[v[k]]=w[k];
                siftup_ch8(pos[v[k]]);
                
            }
            k=next[k];
        }
    }
    
    printf("result: %d", sum);
    
    getchar();
    getchar();
     */
    return 0;
}
