#include<stdio.h>
#include<limits.h>

/*
6.利用分治算法的思想编写C语言函数int find_median(int a[], int m, int b[], int n)，
在长度分别为m和n的两个排序整型数组中找出总体的中位值，其中a为升序排列，b为降序排列。说明时间复杂度。
中位值定义为第（m+n）/ 2 小的元素。
 */
int find_kth_element(int a[], int m, int b[], int n, int k) {

    // 根据 数组a 和数组 b 的大小来按比例分配 i 和 j 的值
    int i = (int)((double)m / (m + n) * (k - 1));
    int j = (k - 1) - i;

    // 防止超界
    int Ai_1 = ((i == 0) ? INT_MIN : a[i - 1]);
    int Bj_1 = ((j == 0) ? INT_MIN : b[j - 1]);
    int Ai   = ((i == m) ? INT_MAX : a[i]);
    int Bj   = ((j == n) ? INT_MAX : b[j]);

    if (Bj_1 < Ai && Ai < Bj)
        return Ai;
    else if (Ai_1 < Bj && Bj < Ai)
        return Bj;

    if (Ai < Bj)
        return find_kth_element(a + i + 1, m - i - 1, b, j, k - i);
    else
        return find_kth_element(a, i, b + j + 1, n - j - 1, k - j);
}

int find_median(int a[], int m, int b[], int n)
{
    int k = (m + n) / 2;
    return find_kth_element(a, m, b, n, k);
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8, 10};
    printf("%d\n", find_median(a, 5, b, 5));
    return 0;
}
