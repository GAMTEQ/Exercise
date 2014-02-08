//
//  MySort.cpp
//  Algorithms
//
//  Created by 王 崇欢 on 14-2-8.
//  Copyright (c) 2014年 王 崇欢. All rights reserved.
//

#include "GSort.h"

char *GSort::bsearch(const char *key, /*要查找的元素指针*/
                     const char *base, /*数组头元素指针*/
                     size_t nelem, /*数组元素个数*/
                     size_t size, /*元素的字节数*/
                     _Cmpfun *cmp /*比较函数*/)
{
    const char *p = (const char *)base; // 下界
    size_t n = nelem; // 上界（其实是从下界到上界有几个元素）
    while(n > 0) {
        const size_t pivot = n >> 1; // 每次取上下界的中间
        const char *const q = p + size * pivot; // 中间元素指针
        const int val = (*cmp)(key, q); // 比较中间元素和key的大小
        if(val < 0) { // key小于中间元素，则上界下移
            n = pivot;
        }
        else if(val == 0) { // key等于中间元素，则查找成功
            return (char *)q;
        }
        else { // key大于中间元素，则下界上移
            p = q + size;
            n -= pivot + 1;
        }
    }
    return NULL;
}

void GSort::qsort(char *base, /*数组元素头指针*/
                  size_t n, /*数组的元素个数*/
                  size_t size, /*元素的字节数*/
                  _Cmpfun *cmp /*比较函数*/)
{
    while(n > 1) {
        size_t i = 0; // 定义前后2个游标和pivot
        size_t j = n - 1;
        char *qi = (char *)base;
        char *qj = qi + size * j;
        char *qp = qj; // pivot定在最右端
        while(i < j) { // 从左右两端同时遍历数组，通过交换ij的值，把小于qp的放左边，大于qp的放右边
            while(i < j && (*cmp)(qi, qp) <= 0) // 把游标qi右移到第一个大于qp的位置
                ++i, qi += size;
            while(i < j && (*cmp)(qp, qj) <= 0) // 把游标qj左移到第一个小于qp的位置
                --j, qj -= size;
            if(i < j) { // 交换qi和qj的值并右移i
                exchange(qi, qj, size);
                ++i, qi += size;
            }
        }
        if(qi != qp) // while结束时，i==j，把pivot放到大小的分界点
            exchange(qi, qp, size);
        j = n - i - 1; // 假设n=6，i=3，则j=2；i表示pivot前的元素个数，j表示pivot后的元素个数
        qi += size; // qi此时指向pivot，右移指向pivot右边的数组头
        if(j < i) { // 递归调用qsort排序短的一半，while迭代排序长的一段，这样可以减少动态内存的占用（栈空间）
            GSort::qsort(qi, j, size, cmp);
            n = i;
        }
        else {
            GSort::qsort(base, i, size, cmp);
            base = qi;
            n = j;
        }
    }
}

void GSort::exchange(char *p1, char* p2, size_t size) {
    char buf[MAX_BUF];
    char *q1 = p1;
    char *q2 = p2;
    size_t len_curr; // 当前要交换的字节数
    size_t len_rest = size; // 待交换的字节数
    while(len_rest > 0)
    {
        len_curr = len_rest < sizeof(buf) ? len_rest : sizeof(buf);
        memcpy(buf, q1, len_curr);
        memcpy(q1, q2, len_curr);
        memcpy(q2, buf, len_curr);
        len_rest -= len_curr;
        q1 += len_curr;
        q2 += len_curr;
    }
    
}











