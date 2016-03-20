//
//  chapter1.c
//  Study-AhaAlgorithms
//
//  Created by Mark Lewis on 15-10-3.
//  Copyright (c) 2015年 TechLewis. All rights reserved.
//

#include "chapter1.h"


#pragma mark -  quickSort函数使用
/*
 quickSort函数的使用
 int numArray[101];
 
 for (int i = 0; i< 101; i++)
 {
 int num = arc4random()%9999;
 numArray[i] = num;
 }
 
 quickSort(numArray, 0, 100);
 
 
 for (int i = 0; i< 101; i++)
 {
 printf("array[i] = %d\n", numArray[i]);
 }
 */


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
struct student
{
    char name[21];
    int age;
};


void bubbleSort(int time)
{
    struct student array[100], temp;
    int i, j, n;
    n = time;
    for (i=1; i<=time; i++)
    {
        printf("请输入第%d个name\n", i);
        scanf("%s", array[i].name);
    }
    
    // SORT
    for (i = 1; i <= n-1; i++)
    {
        for (j = 1; j <= n-i; j++)
        {
            if( (array[j].name)[0] > (array[j+1].name)[0])
            {
                // 比较大小并交换
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    printf("排序后：");
    for (i = 1; i <= n; i++)
    {
        printf("%s\n", array[i].name);
    }
    printf("\n");
}

#pragma mark - Easy Sort
// int array[11] = {0, 8, 100, 50, 22, 15, 6, 1, 1000, 999, 0};
// printf("arrayLength = %d\n" ,(int)(sizeof(array)/sizeof(int)));
// 模仿桶排序 对一千以内的数字排序
void bucketSort(int n)
{
    printf("%p\n", &n);
    int bucketArray[1001], i, j, t;
    for (i = 0; i<=1000; i++) bucketArray[i] = 0; //将数组中元素初始化为0
    printf("%p\n", &bucketArray[1001]);
    // 为什么参数n的值会变成0 ？
    
    for (i = 1; i <= n; i++)
    {
        // 排序n个输入的数
        printf("请输入第%d个数字\n", i);
        scanf("%d", &t); // 把每一个数读入到变量t中
        bucketArray[t]++;
    }
    
    
    // Sort
    printf("排序后：");
    for (i = 0; i<=1000; i++)
    {
        for (j = 1; j<=bucketArray[i]; j++) // 数组中1-10出现的元素，出现几次打印几次
        {
            printf("%d ", i);
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