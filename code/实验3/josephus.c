//c语言用数组实现约瑟夫环
#include<stdio.h>
#include<stdlib.h>

int josephus(int n, int m);
int main()
{
    int p, q, r;
    printf("请输入参选人的个数p和开始的位置q：\n");
    scanf("%d, %d", &p, &q);
    r = josephus(p, q);
    printf("最后那个人的初始位置是：%d\n", r);
    return 0;
}

int josephus(int n, int m)
{
    int i, j = 0, s = 0, l;
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    a[n] = -1;
    for (i = 0; j != n; i++)
    {
        if (a[i] == -1)
            i = 0;
        if (a[i] != 0 && a[i] != -1)
            s++;
        if (s == m)
        {
            l = a[i];
            a[i] = 0;
            j++;
            s = 0;
        }
    }
    return l;
}
