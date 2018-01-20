#include<stdio.h>

void func(int a[], int first, int last)
{
    if (first >= last)
        return ;

    printf("%d, ", a[(first + last)/2]);   // 用于测试
    if (a[(first + last)/2 < 0])
    {
        func(a, first, (first + last)/2);
        return ;
    }
    func(&a[(first + last)/2 + 1], 0, (last - first - 1)/2);
    return ;
}

int main(int argc, char const *argv[])
{
    int test1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int test2[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    func(test1, 0, 9);
    func(test2, 0, 9);
    return 0;
}
