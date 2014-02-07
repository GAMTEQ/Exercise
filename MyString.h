//
//  MyString.h
//  Algorithms
//
//  Created by 王 崇欢 on 14-2-7.
//  Copyright (c) 2014年 王 崇欢. All rights reserved.
//

#ifndef Algorithms_MyString_h
#define Algorithms_MyString_h

typedef int size_t;

class MyString {
    // 从字符数组s中（长度为n），找到字符c第一次出现的位置，并返回该位置的指针
    static char *(memchr)(const char *s, int c, size_t n) {
        const unsigned char uc = c;
        const unsigned char *su;
        for(su = s; 0 < n; ++su, --n) {
            if(*su == uc) {
                return ((char*)su);
            }
        }
        return NULL;
    }
    // 比较2个长度都为n的字符串大小，s1小-1等0大1
    static int (memcmp)(const char *s1, const char *s2, size_t n) {
        const unsigned char *su1, *su2;
        for(su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, --n) {
            if(*su1 != *su2) {
                return ((*su1 < *su2) ? -1 : 1);
            }
        }
        return 0;
    }
    // 从s2中复制n个字符到s1
    static char *(memcpy)(char *s1, const char *s2, size_t n) {
        char *su1;
        const char *su2;
        for(su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, --n) {
            *su1 = *su2;
        }
        return s1;
    }
    //memcpy与memmove的目的都是将N个字节的源内存地址的内容拷贝到目标内存地址中。
    //但当源内存和目标内存存在重叠时，memcpy会出现错误，而memmove能正确地实施拷贝，但这也增加了一点点开销。
    //memmove的处理措施：
    //（1）当源内存的首地址等于目标内存的首地址时，不进行任何拷贝
    //（2）当源内存的首地址大于目标内存的首地址时，实行正向拷贝
    //（3）当源内存的首地址小于目标内存的首地址时，实行反向拷贝
    static char *(memmove)(char *s1, const char *s2, size_t n) {
        char *sc1 = s1;
        const char *sc2 = s2;
        // s2----s1----------s2+n-----s1+n
        if(sc2 < sc1 && sc1 < sc2 + n) {
            for(sc1 += n, sc2 += n; 0 < n; --n) {
                *--sc1 = *--sc2;
            }
        }
        // s1----s2-------s2+n
        // s2--------s2+n----s1
        else {
            for(; 0 < n; --n) {
                *sc1++ = *sc2++;
            }
        }
        return s1;
    }
    // 把字符串的前n个元素都置成字符c
    static char *(memset)(char *s, int c, size_t n) {
        const unsigned char uc = c;
        unsigned char *su;
        for(su = s; 0 < n; ++su, --n) {
            *su = uc;
        }
        return s;
    }
    // 把字符串s2的前n个字符拼接到字符串s1的末尾
    static char *(strncat)(char *s1, const char *s2, size_t n) {
        char *s;
        for(s = s1; *s != '\0'; ++s) {
            ; // 找到s1的最后一个元素
        }
        for(; 0 < n && *s2 != '\0'; --n) {
            *s++ = *s2++;
        }
        *s = '\0';
        return s1;
    }
    // 比较2个字符串前n个字符的大小，同memcmp，但是strncmp遇到'\0'就停了
    static int (strncmp)(const char *s1, const char *s2, size_t n) {
        for(; 0 < n; ++s1, ++s2, --n) {
            if(*s1 != *s2) {
                return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
            }
            else if(*s1 == '\0') {
                return 0;
            }
        }
        return 0;
    }
    // 把字符串s2拼接到字符串s1末尾
    static char *(strcat)(char *s1, const char *s2) {
        char *s;
        for(s = s1; *s != '\0'; ++s) {
            ;
        }
        for(; (*s = *s2) != '\0'; ++s, ++s2) {
            ;
        }
        return s1;
    }
    // 比较2个字符串的大小
    static int (strcmp)(const char *s1, const char *s2) {
        for(; *s1 == *s2; ++s1, ++s2) {
            if(*s1 == '\0') {
                return 0;
            }
        }
        return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
    }
    // 把字符串s2复制到s1直到'\0'
    // s1----s2-----
    // s2----s1----- 这种情况就不行了，所以该函数不能处理重叠的情况
    static char *(strcpy)(char *s1, const char *s2) {
        char *s;
        for(s = s1; (*s++ = *s2++) != '\0';) {
            ;
        }
        // 重新生命一个s不改变s1是为了返回s1可以链式操作
        // 比如strlen(strcpy(newStr, oldStr));
        return s1;
    }
    // 计算字符串的长度，不包括'\0'
    static size_t (strlen)(const char *s) {
        const char *sc;
        for(sc = s; *sc != '\0'; ++sc) {
            ;
        }
        return sc - s;
    }
    // 从字符串s中找到c第一次出现的位置并返回其指针
    static char *(strchr)(const char *s, int c) {
        const char ch = c;
        for(; *s != ch; ++s) {
            if(*s == '\0') {
                return NULL;
            }
        }
        return (char *)s;
    }
    // 返回s1中在s2中存在的第一个字符的位置
    static size_t (strcspn)(const char *s1, const char *s2) {
        const char *sc1, *sc2;
        for(sc1 = s1; *sc1 != '\0'; ++sc1) {
            for(sc2 = s2; *sc2 != '\0'; ++sc2) {
                if(*sc1 == *sc2) {
                    return sc1 - s1;
                }
            }
        }
        return sc1 - s1;
    }
    // 返回s1中在s2中存在的第一个字符本身
    static char *(strpbrk)(const char *s1, const char *s2) {
        const char *sc1, *sc2;
        for(sc1 = s1; *sc1 != '\0'; ++sc1) {
            for(sc2 = s2; *sc2 != '\0'; ++sc2) {
                if(*sc1 == *sc2) {
                    return (char *)sc1;
                }
            }
        }
        return NULL;
    }
    // 返回s1中第一个不在s2中的字符的下标
    static size_t (strspn)(const char *s1, const char *s2) {
        const char *sc1, *sc2;
        for(sc1 = s1; *sc1 != '\0'; ++sc1) {
            for(sc2 = s2; ; ++sc2) {
                if(*sc2 == '\0') {
                    return sc1 - s1;
                }
                else if(*sc1 == *sc2) {
                    break;
                }
            }
        }
        return sc1 - s1;
    }
    // 返回字符串s中最后一个字符c的位置
    static char *(strrchr)(const char *s, int c) {
        const char ch = c;
        const char *sc;
        for(sc = NULL; ; ++s) {
            if(*s == ch)
                sc = s;
            if(*s == '\0')
                return (char *)sc;
        }
    }
    // 返回s1中s2第一次出现的位置
    static char *(strstr)(const char *s1, const char *s2) {
        if(*s2 == '\0') {
            return (char *)s1;
        }
        // 遍历s1中每一个以s2首字符起始的字符
        for(; (s1 = strchr(s1, *s2)) != NULL; ++s1) {
            const char *sc1, *sc2;
            for(sc1 = s1, sc2 = s2; ; ) {
                // s1中当前字符的后续串直到s2的末尾都和s2相同
                if(*++sc2 == '\0') {
                    return (char *)s1;
                }
                // s1中当前字符的后续串匹配失败
                else if(*++sc1 != *sc2) {
                    break;
                }
            }
        }
        return NULL;
    }
    // 返回s1中以s2分割的下一个子串
    // 参考 strtok_r strsep
    // 只取s2的首字符
    // 第一个参数：第一次调用传s1，后续调用都传NULL
    static char *(strtok)(char *s1, const char *s2) {
        char *sbegin, *send;
        static char *ssave = "";
        sbegin = s1 ? s1 : ssave;
        // 返回sbegin中第一个不在s2中的字符的下标
        // 所以12...34用.分割，就成了12 34，跳过了多个.
        sbegin += strspn(sbegin, s2);
        if(*sbegin == '\0') {
            ssave = "";
            return NULL;
        }
        send = sbegin + strcspn(sbegin, s2); // 返回sbegin中第一个在s2中的字符的下标
        if(*send != '\0') {
            *send++ = '\0';
        }
        ssave = send;
        return sbegin;
    }
};

#endif













