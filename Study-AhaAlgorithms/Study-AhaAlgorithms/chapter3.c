//
//  chapter3.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-5.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//

#include "chapter3.h"

// 排列1-9的任意数的全排列
void numberPermutation()
{
    int a, b, c;
    for (a=1; a<=3; a++)
    {
        for (b=1; b<=3; b++)
        {
            for (c=1; c <= 3;c++)
            {
                if (a!=b && a!=c && b!=c)
                {
                    printf("%d%d%d\n", a, b, c);
                }
            }
        }
    }
}

#pragma mark - 火柴棍等式
/*
int a, b, c, m, sum=0; // sum是用来计数的, 因此一定要初始化为0
scanf("%d", &m);

// 开始枚举a和b
for (a=0; a<=1111; a++)
{
    for (b=0; b<=1111; b++)
    {
        c=a+b;
        
        if (fun(a)+fun(b)+fun(c)==m-4)
        {
            printf("%d+%d=%d\n", a, b, c);
            sum++;
        }
    }
}

printf("sum=%d\n", sum);
*/
int fun(int x)
{
    int num = 0; // 用来计数的变量， 一定要记得初始化
    int f[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    // 用一个数组来记录0~9每个数字需要用多少根火柴棍
    while (x/10 != 0) // 如果x/10的商不等于0的话, 说明这个数至少有二位
    {
        // 获得x的末尾数字并将此数所需要用到的火柴棍根数累加到num中
        num += f[x%10];
        x = x/10; // 去掉x的末尾数字， 例如x的值为123则x/10=12
    }
    
    // 最后加上此时x所需要用到的火柴棍的根数(此时x一定是一位数)
    num += f[x];
    
    return num; // 返回需要火柴棍的总根数
}

#pragma mark 0 暴力的枚举
/*
int a, b, c, d, e, f, g, h, i, total=0;
int index = 1;
for(a=1;a<=9;a++)
for(b=1;b<=9;a++)
for(c=1;c<=9;a++)
for(d=1;d<=9;a++)
for(e=1;e<=9;a++)
for(f=1;f<=9;a++)
for(g=1;g<=9;a++)
for(h=1;h<=9;a++)
for(i=1;i<=9;a++)
{
    NSLog(@"loop%d", index++);
    if(a!=b  && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
       && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
       && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
       && d!=e && d!=f && d!=g && d!=h && d!=i
       && e!=f && e!=g && e!=h && e!=i
       && f!=g && f!=h && f!=i
       && g!=h && g!=i
       && h!=i
       && a*100+b*10+c+d*100+e*10+f==g*100+h*10+i)
    {
        total++;
        NSLog(@"%d%d%d + %d%d%d = %d%d%d", a, b, c, d, e, f, g, h, i);
    }
    
}

NSLog(@"total = %d", total/2);
*/