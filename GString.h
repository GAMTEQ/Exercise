//
//  MyString.h
//  Algorithms
//
//  Created by 王 崇欢 on 14-2-7.
//  Copyright (c) 2014年 王 崇欢. All rights reserved.
//

#ifndef Algorithms_MyString_h
#define Algorithms_MyString_h

extern "C" {
#include <string.h>
#include <stdlib.h>
}

class GString {
    // 从字符数组s中（长度为n），找到字符c第一次出现的位置，并返回该位置的指针
    static char *memchr(const char *s, int c, size_t n);
    // 比较2个长度都为n的字符串大小，s1小-1等0大1
    static int memcmp(const char *s1, const char *s2, size_t n);
    // 从s2中复制n个字符到s1
    static char *memcpy(char *s1, const char *s2, size_t n);
    //memcpy与memmove的目的都是将N个字节的源内存地址的内容拷贝到目标内存地址中。
    //但当源内存和目标内存存在重叠时，memcpy会出现错误，而memmove能正确地实施拷贝，但这也增加了一点点开销。
    //memmove的处理措施：
    //（1）当源内存的首地址等于目标内存的首地址时，不进行任何拷贝
    //（2）当源内存的首地址大于目标内存的首地址时，实行正向拷贝
    //（3）当源内存的首地址小于目标内存的首地址时，实行反向拷贝
    static char *memmove(char *s1, const char *s2, size_t n);
    // 把字符串的前n个元素都置成字符c
    static char *memset(char *s, int c, size_t n);
    // 把字符串s2的前n个字符拼接到字符串s1的末尾
    static char *strncat(char *s1, const char *s2, size_t n);
    // 比较2个字符串前n个字符的大小，同memcmp，但是strncmp遇到'\0'就停了
    static int strncmp(const char *s1, const char *s2, size_t n);
    // 把字符串s2拼接到字符串s1末尾
    static char *strcat(char *s1, const char *s2);
    // 比较2个字符串的大小
    static int strcmp(const char *s1, const char *s2);
    // 把字符串s2复制到s1直到'\0'
    // s1----s2-----
    // s2----s1----- 这种情况就不行了，所以该函数不能处理重叠的情况
    static char *strcpy(char *s1, const char *s2);
    // 计算字符串的长度，不包括'\0'
    static size_t strlen(const char *s);
    // 从字符串s中找到c第一次出现的位置并返回其指针
    static char *strchr(const char *s, int c);
    // 返回s1中在s2中存在的第一个字符的位置
    static size_t strcspn(const char *s1, const char *s2);
    // 返回s1中在s2中存在的第一个字符本身
    static char *strpbrk(const char *s1, const char *s2);
    // 返回s1中第一个不在s2中的字符的下标
    static size_t strspn(const char *s1, const char *s2);
    // 返回字符串s中最后一个字符c的位置
    static char *strrchr(const char *s, int c);
    // 返回s1中s2第一次出现的位置
    static char *strstr(const char *s1, const char *s2);
    // 返回s1中以s2分割的下一个子串
    // 参考 strtok_r strsep
    // 只取s2的首字符
    // 第一个参数：第一次调用传s1，后续调用都传NULL
    static char *strtok(char *s1, const char *s2);
};

#endif













