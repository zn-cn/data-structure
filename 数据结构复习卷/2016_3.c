#include<stdio.h>

/*
编写C语言函数void move(int a[], int n) 将整数数组 a （长度为n）中
所有负数移到所有正数之前（0不需要移动），要求时间复杂度为O(n)，并且只是
用常数长度的辅助存储。
*/
// 寻找最靠近0的非负整数
int find_pivot_index(int a[], int n)
{
    int pivotIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            if (pivotIndex >= 0)
                pivotIndex = (a[pivotIndex] > a[i]) ? i : pivotIndex;
            else
                pivotIndex = i;
        }
    }
    return pivotIndex;
}

// 交换
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void move(int a[], int n)
{
    int pivotIndex = find_pivot_index(a, n);
    int pivotValue = a[pivotIndex];
    int left = 0, right = n - 1;
    while (left < right) {
        while (a[left] < pivotValue && left < right)
            left++;
        while (a[right] >= pivotValue && left < right)
            right--;
        swap(&a[left], &a[right]);
    }
}

// 打印数组
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[10] = {10, 9, 8, 4, 3, 0, -1, -2, -3, -4};
    move(a, 10);
    print_array(a, 10);
    return 0;
}


