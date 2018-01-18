#include<stdio.h>

/*
编写C语言函数 int is_index(int a[], int n) 判断升序排列的整数数组a（长度为n）中
是否存在a[i] = i；如果存在，返回TRUE，否则返回FALSE。说明程序的时间复杂度是多少。
 */

int is_index(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == i)
            return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 3, 5};
    printf("%d\n", is_index(a, 5));
    return 0;
}
