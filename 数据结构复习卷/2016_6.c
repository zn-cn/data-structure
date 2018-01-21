#include<stdio.h>
#include<limits.h>
/*
6.编写C语言函数 int find_kth_element(int a[], int m, int b[], int n, int k)，在长度分别为m和n的两个
已经按顺序排列的整型数组中找到总体上第k小的元素。要求时间复杂度为 O(log m + log n)。
 */

// 有些许问题
int find_kth_element_old(int a[], int m, int b[], int n, int k)
{

    // 根据 数组a 和数组 b 的大小来按比例分配 i 和 j 的值
    int i = (int)((double)m / (m + n) * (k - 1));
    int j = (k - 1) - i;

    // 防止超界
    int A_i_1 = ((i == 0) ? INT_MIN : a[i - 1]);
    int B_j_1 = ((j == 0) ? INT_MIN : b[j - 1]);
    int A_i   = ((i == m) ? INT_MAX : a[i]);
    int B_j   = ((j == n) ? INT_MAX : b[j]);

    if (B_j_1 < A_i && A_i < B_j)
        return A_i;
    else if (A_i_1 < B_j && B_j < A_i)
        return B_j;

    // 这里由于传入find_kth_element()函数的指针以及变成 a+i+1，所以讲数组长度限定为 m-i，
    // k变为 k-i，可自行画图理解（最重要的是理解函数传入的是指针，如 main（）函数中传入的 a，其实传入的也是数组的头指针）
    if (A_i < B_j)
        return find_kth_element(a + i + 1, m - i - 1, b, j, k - i);
    else
        return find_kth_element(a, i, b + j + 1, n - j - 1, k - j);
}

// 新版先放着
int find_kth_element(int *a, int m, int *b, int n, int k) {
    if (m == 0)
        return b[k - 1];

    if (n == 0)
        return a[k - 1];

    if (k == 1)
        return (a[0] < b[0]) ? a[0] : b[0];

    if (k == m + n)
        return (a[m - 1] > b[n - 1]) ? a[m - 1] : b[n - 1];

    int i = ((double) m) / (m + n) * (k - 1);
    int j = k - 1 - i;
    if (j >= n)
    {
        j = n - 1;
        i = k - n;
    }
    if (((i == 0) || (a[i - 1] <= b[j])) && (b[j] <= a[i]))
        return b[j];
    if (((j == 0) || (b[j - 1] <= a[i])) && (a[i] <= b[j]))
        return a[i];
    if (a[i] <= b[j])
        return find_kth_element(a + i + 1, m - i - 1, b, j, k - i - 1);
    else
        return find_kth_element(a, i, b + j + 1, n - j - 1, k - j - 1);


}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8, 10};
    int k = 3;
    int result = find_kth_element(a, 5, b, 5, k);
    printf("the %dth num is %d\n", k, result);

    return 0;
}
