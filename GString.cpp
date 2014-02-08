//
//  GString.cpp
//  Algorithms
//
//  Created by 王 崇欢 on 14-2-8.
//  Copyright (c) 2014年 王 崇欢. All rights reserved.
//

#include "GString.h"

char *GString::memchr(const char *s, int c, size_t n) {
    const unsigned char uc = c;
    const unsigned char *su;
    for(su = (const unsigned char *)s; 0 < n; ++su, --n) {
        if(*su == uc) {
            return ((char*)su);
        }
    }
    return NULL;
}

int GString::memcmp(const char *s1, const char *s2, size_t n) {
    const unsigned char *su1, *su2;
    for(su1 = (const unsigned char *)s1, su2 = (const unsigned char *)s2;
        0 < n; ++su1, ++su2, --n)
    {
        if(*su1 != *su2) {
            return ((*su1 < *su2) ? -1 : 1);
        }
    }
    return 0;
}

char *GString::memcpy(char *s1, const char *s2, size_t n) {
    char *su1;
    const char *su2;
    for(su1 = s1, su2 = s2; 0 < n; ++su1, ++su2, --n) {
        *su1 = *su2;
    }
    return s1;
}

char *GString::memmove(char *s1, const char *s2, size_t n) {
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

char *GString::memset(char *s, int c, size_t n) {
    const unsigned char uc = c;
    unsigned char *su;
    for(su = (unsigned char *)s; 0 < n; ++su, --n) {
        *su = uc;
    }
    return s;
}

char *GString::strncat(char *s1, const char *s2, size_t n) {
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

int GString::strncmp(const char *s1, const char *s2, size_t n) {
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

char *GString::strcat(char *s1, const char *s2) {
    char *s;
    for(s = s1; *s != '\0'; ++s) {
        ;
    }
    for(; (*s = *s2) != '\0'; ++s, ++s2) {
        ;
    }
    return s1;
}

int GString::strcmp(const char *s1, const char *s2) {
    for(; *s1 == *s2; ++s1, ++s2) {
        if(*s1 == '\0') {
            return 0;
        }
    }
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
}

char *GString::strcpy(char *s1, const char *s2) {
    char *s;
    for(s = s1; (*s++ = *s2++) != '\0';) {
        ;
    }
    // 重新生命一个s不改变s1是为了返回s1可以链式操作
    // 比如strlen(strcpy(newStr, oldStr));
    return s1;
}

size_t GString::strlen(const char *s) {
    const char *sc;
    for(sc = s; *sc != '\0'; ++sc) {
        ;
    }
    return sc - s;
}

char *GString::strchr(const char *s, int c) {
    const char ch = c;
    for(; *s != ch; ++s) {
        if(*s == '\0') {
            return NULL;
        }
    }
    return (char *)s;
}

size_t strcspn(const char *s1, const char *s2) {
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

char *GString::strpbrk(const char *s1, const char *s2) {
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

size_t GString::strspn(const char *s1, const char *s2) {
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

char *GString::strrchr(const char *s, int c) {
    const char ch = c;
    const char *sc;
    for(sc = NULL; ; ++s) {
        if(*s == ch)
            sc = s;
        if(*s == '\0')
            return (char *)sc;
    }
}

char *GString::strstr(const char *s1, const char *s2) {
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

char *GString::strtok(char *s1, const char *s2) {
    char *sbegin, *send;
    static const char *ssave = "";
    sbegin = s1 ? s1 : (char *)ssave;
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





























