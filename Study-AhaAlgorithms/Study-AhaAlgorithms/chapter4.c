//
//  chapter4.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-30.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//

#include <stdio.h>

/*
// DFS函数的使用
int a[10], book[10], n; // C语言的全局变量在没有赋值以前，默认为0，因此这里的book数组无需初始化0
// 注意全局变量是这样的
int total=0;			// 记录多少种排列方法








// 深度优先搜索
void dfs(int step)      // step表示现在站在第几个盒子前面
{
	int i;
	if(step == n+1)
	{
		// 如果站在第n+1个盒子面前，则表示前n个盒子已经排列好了
		
		// 输出一种排列(1~n盒子中的数字)
		for(i=1;i<=n;i++)
		{
			printf("%d", a[i]);
		}
        
        total++;
		// ++times;
		printf("\n");
        
		return; // 返回前一步（最近一次调用dfs函数的地方）
	}
	
	// 此时站在第step个盒子面前，应该放哪张牌呢？
	// 按照1、2、3、4、5.......n的顺序一一尝试
	for(i=1;i<=n;i++)
	{
		// 判断扑克牌i是否在手上
		if(book[i]==0)
		{
			// 开始尝试使用i号扑克牌
			a[step]=i; // 将i号扑克牌放入第step个盒子中
			book[i]=1; // 将booki[1]设为1，表示i号扑克牌已经不在手中
            
			// 第step个盒子已经放好扑克牌，接下来需要走到下一个盒子前面
			// 这里通过函数的递归调用来实现(自己调用自己)
			// 这是非常重要的一步， 一定要将刚才尝试的扑克牌收回，才能进行下一次尝试
			dfs(step+1);
			book[i]=0;
		}
	}
    
	return;
}

 
int main(int argc, const char * argv[])
{
    // insert code here...
    
    for (int i=0; i < 10; i++)
    {
        printf("a[%d] == %d\n", i, book[i]);
    }
    
	scanf("%d", &n); // 输入的时候要注意n为1~9之间的整数
	dfs(1); // 首先站在1号小盒子前面
	printf("\n全排列一共%d种排列方法\n", total);
	
    return 0;
}
 */