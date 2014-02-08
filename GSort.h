//
//  MySort.h
//  Algorithms
//
//  Created by 王 崇欢 on 14-2-8.
//  Copyright (c) 2014年 王 崇欢. All rights reserved.
//

#ifndef Algorithms_MySort_h
#define Algorithms_MySort_h

extern "C" {
#include <string.h>
#include <stdlib.h>
}

typedef int _Cmpfun(const char *, const char *);
#define MAX_BUF 256

class GSort {
public:
    // 二分查找：在一个有序(从小到大)的数组里查找指定元素
    static char *bsearch(const char *key, /*要查找的元素指针*/
                         const char *base, /*数组头元素指针*/
                         size_t nelem, /*数组元素个数*/
                         size_t size, /*元素的字节数*/
                         _Cmpfun *cmp /*比较函数*/);
    // 用快速排序给数组(char base[size])[n]排序
    static void qsort(char *base, /*数组元素头指针*/
                      size_t n, /*数组的元素个数*/
                      size_t size, /*元素的字节数*/
                      _Cmpfun *cmp /*比较函数*/);
private:
    // 尽可能多的交换数据，但不能超过MAX_BUF
    // 比如size是10，MAX_BUF是4
    static void exchange(char *p1, char* p2, size_t size);
};

#endif





























