//
//  main.m
//  Study-Aha-Algorithms
//
//  Created by Mark Lewis on 15-8-13.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <stdio.h>
void bucketSort(int n);
void bubbleSort(int time);
void quickSort(int array[], int left, int right);
void printBinary(int number);

#include <stdio.h>
#define PositiveInfinity 99999999;
#include <stdio.h>

int dis[7], book[7]={0};
int h[7], pos[7], size;

// swap func
void swap(int x, int y)
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
void siftdown(int i)
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
            swap(t ,i);
            i=t;
        }
        else
        {
            flag = 1;
        }
    }
    
    return;
}

void siftup(int i)
{
    int flag=0;
    if(i == 1) return;
    
    while(i!=1 && flag==0)
    {
        if(dis[h[i]] < dis[h[i/2]])
        {
            swap(i, i/2);
        }
        else
        {
            flag=1;
        }
        
        i=i/2;
    }
    
    return;
}
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


//
int pop()
{
    int t;
    t=h[1];
    pos[t]=0;
    h[1]=h[size];
    pos[h[1]]=1;
    size--;
    siftdown(1);
    return t;
}

int main(int argc, const char * argv[])
{
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
    NSDate *startTime = [NSDate date];
    
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
        siftdown(i);
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
                siftup(pos[v[k]]);
                
            }
            k=next[k];
        }
    }
    
    NSDate *endTime = [NSDate date];
    NSLog(@"\nspend time = %f", [endTime timeIntervalSinceDate:startTime]);
    
    printf("result: %d", sum);
    return 0;
}


#pragma mark - 最小生成树算法
/*
{
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
    
    
    
    int main(int argc, const char * argv[])
    {
        int i;
        
        scanf("%d %d", &n, &m);
        
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        }
        NSDate *startTime = [NSDate date];
        
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
        
        NSDate *endTime = [NSDate date];
        NSLog(@"spend time = %f", [endTime timeIntervalSinceDate:startTime]);
        
        printf("%d", sum);

}
 */
#pragma mark - 输出二进制字符串算法
void printBinary(int number)
{
    int temp = ( sizeof(number)<<3 ) - 1;
    
    while ( temp >= 0 )
    {
        int value = (number>>temp) & 1;
        printf("%d", value);
        
        //
        temp--;
        
        if ( (temp + 1) % 4 == 0 )
        {
            printf(" ");
        }
    }
    
    printf("\n");
}

    #pragma mark - Bellman-Ford队列优化算法
/*
    int dis[20], k, n, m, i, u[20], v[20], w[20];
    int book[20], first[20], next[20];
    int que[101], head=1, tail=1;
    int inf = 99999999;
    
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
                scanf("%d,%d,%d", &u[i], &v[i], &w[i]);
                
                // 邻接表的核心代码, review
                next[i] = first[u[i]];
                first[u[i]] = i;
            }
    
    NSDate *startTime = [NSDate date];
    
    // 1号顶点入队
    que[tail]=1;
    tail++;
    book[1]=1; // mark - first point in the queue
    
    
    while(head<tail)
    {
        k=first[que[head]];
        while(k != 0 && k!=-1)
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
    
    NSDate *endTime = [NSDate date];
    NSLog(@"spend time : %f", [startTime timeIntervalSinceDate:endTime]);
    // print short path
    for(i=1;i<=n;i++)
    {
        printf("%d ", dis[i]);
    }

}
 */
    #pragma mark - Bellman-Ford非优化算法
    /*
    int dis[10], k, i, n, m, u[10], v[10], w[10], check, flag;
    int inf = 99999999;
    
    scanf("%d %d", &n, &m);
    
    // load sides
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    NSDate *startDate = [NSDate date];
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
    
    NSDate *finishedDate = [NSDate date];
    NSLog(@"spend time: %f\n", [finishedDate timeIntervalSinceDate:startDate]);
    
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
    */


    #pragma mark - 使用DFS对图进行遍历
    /*
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
        NSLog(@"\n%d ", que[i]);
    }
     */
    
/* main函数里的，使用代码
 int numArray[1000];
 
 for (int i = 0; i< 1000; i++)
 {
 int num = arc4random()%9999;
 numArray[i] = num;
 }
 
 
 NSLog(@"\n");
 quickSort(numArray, 0, 999);
 // 输出排序后的结果
 for (int i = 0; i< 1000; i++)
 {
 printf("array[i] = %d\n", numArray[i]);
 }
 NSLog(@"\n排序完成");
 
 playCardGame();
 */
int a[101], n;


struct queue
{
    int data[1000];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

void playCardGame()
{
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i, t;
    
    // initialize queue
    q1.head=1;
    q1.tail=1;
    q2.head=1;
    q2.tail=1;
    
    // inititalize stack
    s.top=0;
    
    //初始化用来标记的数组， 用来标记桌上已经有的牌
    for(i=1;i<=9;i++)	book[i] = 0;
    
    // 依次向队列中插入6张牌
    for(i=1;i<=6;i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    
    // 小哈手中的6张牌
    for(i=1;i<=6;i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    NSLog(@"\n输入完成");
    // 当队列为空时执行循环
    while(q1.head<q1.tail && q2.head<q2.tail)
    {
        t=q1.data[q1.head];	// 小哼出了一张牌
        
        // 判断小哼当前打出的牌是否能赢牌
        if(book[t]==0) //表示桌上没有牌面为t的牌
        {
            // 小哼此轮没有赢牌
            // 小哼已经打出一张牌， 所以要把打出的牌出队
            q1.head++;
            s.top++;
            
            s.data[s.top]=t; // 再把打出的牌放在桌上， 即入栈
            book[t]=1; // 标记桌上现在已经出有牌面为t的牌
        }
        else
        {
            // 小哼此轮可以赢牌
            // 小哼已经打出一张牌， 所以要把打出的牌出队
            q1.head++;
            q1.data[q1.tail]=t; // 紧接着把打出的牌放到手中牌的末尾
            q1.tail++;
            
            // 把桌上可以赢得的牌依次放到手中牌的末尾
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0; // 依次取消赢得牌的标记
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
            
            // 收回桌上赢到的最后一张牌面为T的牌
            book[s.data[s.top]] = 0;
            q1.data[q1.tail] = s.data[s.top];
            q1.tail++;
            s.top--;
        }
        
        
        // 小哼手中的牌如果已经打完了，游戏结束
        if(q1.head == q1.tail) break;
        
        
        // 小哈出一张牌
        t=q2.data[q2.head];
        // 判断小哈当前打出的牌是否能赢牌
        if(book[t]==0) //表示桌上没有牌面为t的牌
        {
            // 小哈此轮没有赢牌
            // 小哈已经打出一张牌， 所以要把打出的牌出队
            q2.head++;
            s.top++;
            
            s.data[s.top]=t; // 再把打出的牌放在桌上， 即入栈
            book[t]=1; // 标记桌上现在已经出有牌面为t的牌
        }
        else
        {
            // 小哈此轮可以赢牌
            
            // 小哈已经打出一张牌， 所以要把打出的牌出队
            q2.head++;
            q2.data[q2.tail]=t; // 紧接着把打出的牌放到手中牌的末尾
            q2.tail++;
            
            // 把桌上可以赢得的牌依次放到手中牌的末尾
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0; // 依次取消赢得牌的标记
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
            
            // 收回桌上赢到的最后一张牌面为T的牌
            book[s.data[s.top]] = 0;
            q2.data[q2.tail] = s.data[s.top];
            q2.tail++;
            s.top--;
        }
    }
    
    
    if(q2.head==q2.tail)
    {
        printf("小哼胜利\n");
        printf("小哼当前手中的牌是");
        for(i=q1.head;i<=(q1.tail-1); i++)
        {
            printf(" %d", q1.data[i]);
        }
        
        
        if(s.top>0) // 如果桌上有牌则依次输出桌上的牌
        {
            printf("\n桌上的牌是");
            for(i=1;i<=s.top;i++)
            {
                printf(" %d", s.data[i]);
            }
        }
        
        else
        {
            printf("\n桌上已经没有牌了");
        }
        
    }
    else
    {
        printf("小哈胜利\n");
        printf("小哈当前手中的牌是");
        for(i=q2.head;i<=(q2.tail-1); i++)
        {
            printf(" %d", q2.data[i]);
        }
        
        
        if(s.top>0) // 如果桌上有牌则依次输出桌上的牌
        {
            printf("\n桌上的牌是");
            for(i=1;i<=s.top;i++)
            {
                printf(" %d", s.data[i]);
            }
        }
        
        else
        {
            printf("\n桌上已经没有牌了");
        }
    }
    
    NSLog(@"\n输入完成");
}



#pragma mark - Quick Sort
void quickSort(int array[], int left, int right)
{
    int i, j, t, keyNumber;
    if(left > right) return;
    
    keyNumber = array[left]; // key中存放的是基准数reference number
    i = left;
    j = right;
    
    while (i != j)
    {
        // 顺序很重要， 要先从右往左找
        while(array[j] >= keyNumber && i <j) j--;
        
        // 再从左往右找
        while(array[i] <= keyNumber && i <j) i++;
        
        
        // 当右边找到比基准数小的数字，左边也找到时
        // 交换两个数载数组中的位置
        if (i < j) // 当哨兵i和哨兵j没有相遇时
        {
            t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
    
    
    // 最终，将基准数归位。
    array[left] = array[i];
    array[i] = keyNumber;
    // printf("%d\n", keyNumber);
    
    
    // 归位后基准数左边的数都比reference number小，右边的数都比reference number大
    // 开始分治
    quickSort(array, left, i-1);
    quickSort(array, i+1, right);
    return;
}

// C语言stdlib.h库中的快拍函数使用
int cmp(const void * n1, const void *n2)
{
    return(*(int *)n1-*(int *)n2); //升序排列
}
/*
 int array[11] = {0, 8, 100, 50, 22, 15, 6, 1, 1000, 999, 0};
 qsort(&array[1], 10, sizeof(array[1]), cmp);
 
 
 int a[101], n;
 void useQuickSort()
 {
 //读入数据
 scanf("%d" ,&n);
 for (int i = 1; i <= n; i++) //数组的第二个元素开始的
 {
 // 排序n个输入的数
 printf("请输入第%d个数字\n", i);
 scanf("%d", &a[i]); // 把每一个数读入到变量t中
 }
 
 
 quickSort(1, n); //快速排序函数调用
 
 // 输出排序后的结果
 printf("排序后：");
 for (int i = 1; i <= n; i++)
 {
 printf("%d ", a[i]);
 }
 printf("\n");
 }
 */




#pragma mark - Bubble Sort
void bubbleSort(int time)
{
    int array[100], i, j, temp, n;
    n = time;
    for (i=1; i<=time; i++)
    {
        printf("请输入第%d个数字\n", i);
        scanf("%d", &array[i]);
    }
    
    // SORT
    NSLog(@"排序后：");
    for (i = 1; i <= n-1; i++)
    {
        for (j = 1; j <= n-i; j++)
        {
            if(array[j] > array[j+1])
            {
                // 比较大小并交换
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
    NSLog(@"\n");
}

#pragma mark - Easy Sort
// int array[11] = {0, 8, 100, 50, 22, 15, 6, 1, 1000, 999, 0};
// printf("arrayLength = %d\n" ,(int)(sizeof(array)/sizeof(int)));
// 模仿桶排序 对一千以内的数字排序
void bucketSort(int n)
{
    // printf("%p\n", &n);
    int bucketArray[1001], i, j, t;
    for (i = 0; i<=1000; i++) bucketArray[i] = 0; //将数组中元素初始化为0
    // printf("%p\n", &bucketArray[1001]);
    // 为什么参数n的值会变成0 ？ 参数n与数字的最后一个元素1000挨在一起
    // 访问bucketArray[1001]地址和参数n相同
    
    for (i = 1; i <= n; i++)
    {
        // 排序n个输入的数
        printf("请输入第%d个数字\n", i);
        scanf("%d", &t); // 把每一个数读入到变量t中
        bucketArray[t]++;
    }
    
    
    // Sort
    NSLog(@"排序后：");
    for (i = 0; i<=1000; i++)
    {
        for (j = 1; j<=bucketArray[i]; j++) // 数组中1-10出现的元素，出现几次打印几次
        {
            NSLog(@"%d ", i);
        }
    }
    
    printf("\n");
}
// 第一节，最快最简单的排序
void bucketSortTest()
{
    int array[11], i, j, t;
    for (i = 0; i<=10; i++)
    {
        array[i] = 0; //将数组中元素初始化为0
    }
    
    for (i = 1; i<=5; i++)
    {
        // 排序五个输入的数
        scanf("%d" ,&t); // 把每一个数读入到变量t中
        array[t]++;
    }
    
    
    // Sort
    for (i = 0; i<=10; i++)
    {
        for (j = 1; j<=array[i]; j++) // 数组中1-10出现的元素，出现几次打印几次
        {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}