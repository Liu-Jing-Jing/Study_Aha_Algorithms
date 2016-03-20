//
//  chapter2.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-3.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//
#include "chapter2.h"

#pragma mark - 指针实现链表
// 这里创建一个结构体来表示链表的node类型
struct node
{
	int data;
	struct node *next;
};

void dynamicInsertNode()
{
	struct node *head, *p, *q, *t;
	int i, n, a;
	scanf("%d", &n);
	head=NULL; // head指针初始化为空
	for(i=1;i<=n;i++) // 循环读入n个数
	{
		scanf("%d", &a);
		//  动态申请一个空间，用来存放一个node，并使用临时指针p来指向这个node
		p = (struct node *)malloc(sizeof(struct node));
		p->data=a; // 将数据存储到当前node的data数值域中
		p->next=NULL; // 设置当前node的next指针为空，也就是当前node的下一个节点为空
		
        
        
		if(head == NULL)
		{
			// 如果这是第一个创建的node， 则将head指针指向这个节点
			head=p;
		}
		else
		{
			// 如果不是第一个创建的node，则将上一个node的next指针指向当前节点
            q = NULL;
			q->next=p;
		}
		q=p; // 指针q也指向当前node
	}
    
	// 读入待插入的数
	printf("请输入待插入的数");
	scanf("%d", &a);
	t=head;
	while(t != NULL)
	{
		if(t->next==NULL || t->next->data > a)
		{// 如果当前节点的最后一个节点或者下一个节点的值大于待插入数的时候插入
            
			// 动态申请一个内存空间来存放新增的node
			p = (struct node *)malloc(sizeof(struct node));
            
			p->data = a;
			p->next = t->next;
            
			t->next = p;
			break;
		}
		t=t->next;
	}
    
	// 输出链表中的所有数值
	t=head;
	while(t != NULL)
	{
		printf("%d ", t->data);
		t=t->next; // 继续下一个node
	}
}

/*
 int main()
 {
 dynamicInsertNode();
 
 getchar();
 getchar();
 return 0;
 }
 
 // malloc函数的使用，动态内存分配，回收内存
 int *p;
 p=(int *)malloc(sizeof(int));
 *p=10;
 printf("%d", *p);
 free(p);
 */


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
    printf("\n");
}




#pragma mark -  判断回文string
/*
 int main()
 {
 char a[101], s[101];
 int i, length, mid, next, top;
 
 gets(a);
 length=strlen(a);
 mid=length/2-1;
 
 top=0; //  initialize  stack
 for(i=0;i<=mid;i++)
 {
 s[++top] = a[i];
 }
 
 // 判断奇数还是偶数
 if(length%2==0)
 {
 next = mid+1;
 }
 else
 {
 next = mid+2;
 }
 
 
 // start matching
 for(i=next;i<=length-1;i++)
 {
 if(a[i] != s[top]) break;
 top--;
 
 //
 if(top==0)
 {
 printf("YES");
 }
 else
 {
 printf("NO");
 }
 }
 
 
 getchar();
 getchar();
 return 0;
 }
 
 */
