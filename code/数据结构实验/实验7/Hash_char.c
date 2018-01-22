#include<stdio.h>

// BKDR Hash Function
unsigned int BKDRHash(char *str) {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str) {
        //每转化一位字符，用当前的hash值 * seed，在加上字符的ASCII码。
        //hash * seed, 此处我们可以理解为当前字符串在前一个字符串hash值的基础上，偏移了一个种子的数级距离。
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF); //最后用hash & Ox7FFFFFFF 确保hash值在unsigned int 范围中。
}
