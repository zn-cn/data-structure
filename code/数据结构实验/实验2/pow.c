#include<stdio.h>
#include<time.h>

int getPowByViolence(int n, int m);
int getPowByDivide(int n, int m);
int main(int argc, char const *argv[])
{



    double cpu_time;
    clock_t a, b;

    printf("%d %d\n", getPowByViolence(2, 10), getPowByDivide(2, 10) );

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 10000; ++i)
        {
            getPowByViolence(2, j);
        }

        b = clock();

        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒


        printf("以2为底,%d次方，循环10000次 暴力求解time: %f ms\n", j, cpu_time);
    }
    printf("\n");

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 10000; ++i)
        {
            getPowByDivide(2, j);
        }

        b = clock();
        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒
        printf("以2为底,%d次方，循环10000次 分治求解time: %f ms\n", j, cpu_time);
    }

    printf("\n\n");

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 10000; ++i)
        {
            getPowByViolence(3, j);
        }

        b = clock();
        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒
        printf("以3为底,%d次方，循环10000次 暴力求解time: %f ms\n", j, cpu_time);

    }
    printf("\n");

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 10000; ++i)
        {
            getPowByDivide(3, j);
        }

        b = clock();
        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒
        printf("以3为底,%d次方，循环10000次 分治求解time: %f ms\n", j, cpu_time);
    }

    return 0;
}

// 暴力求解

int getPowByViolence(int n, int m)
{
    int result = n;
    for (int i = 1; i < m; ++i)
    {
        result *= n;
    }
    return result;
}


// 使用递归和分治求解
int getPowByDivide(int n, int m)
{
    if (m == 1)
    {
        return n;
    }
    else
    {
        return getPowByDivide(n, m / 2) * getPowByViolence(n, m - m / 2);
    }
}
