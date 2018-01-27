#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <sys/time.h>

#define SHELL_LEN 10000
#define ROUND  100   // 循环次数
// 希尔的原始序列
long shell_sort(int arr[], int len) {
    int gap, i, j;
    int op = 0;  // 操作次数
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
                op++;
            }
            arr[j + gap] = temp;
            op++;
        }
    return op;
}

// Hibbard 的增量
long shell_sort_Hibbard(int arr[], int len) {
    if (len == 1)
        return 0;
    int op = 0;  // 操作次数
    int k = 0;
    // 找到 HIbbard增量中的上限k
    for (; len / (2 << k) != 1; k++)
        ;
    int gap, i, j;
    int temp;
    for (; k >= 0; k--)
    {
        gap = (2 << k) - 1;
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
                op++;
            }
            arr[j + gap] = temp;
            op++;
        }
    }
    return op;
}

// Knuth增量
long shell_sort_Knuth(int arr[], int len) {
    int gap, i, j;
    int op = 0;  // 操作次数
    int temp;
    for (gap = 1; gap <= len / 9; gap = gap * 3 + 1)
        ;
    for (; gap > 0; gap /= 3)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
                op++;
            }
            arr[j + gap] = temp;
            op++;
        }
    return op;
}

// Gonnet 增量
long shell_sort_Gonnet(int arr[], int len) {
    int gap, i, j;
    int temp;
    int op = 0;  // 操作次数
    for (gap = len; gap > 1; )
    {
        gap = (gap < 5) ? 1 : (gap * 5 - 1) / 11;
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
                op++;
            }
            arr[j + gap] = temp;
            op++;
        }
    }
    return op;
}

// Sedgewick
long shell_sort_Sedgewick(int arr[], int len) {
    int op = 0;  // 操作次数
    int gap, i, j;
    int temp;
    int incs[16] = { /*a1=3,a2=7,a3=16,a4=41,a5=101*/
        1391376,/*a1*a2*a3*a4*a5*/
        463792,/*a2*a3*a4*a5*/
        198768,/*a1*a3*a4*a5*/
        86961,/*a1*a2*a4*a5*/
        33936,/*a1*a2*a3*a5*/
        13776,/*a1*a2*a3*a4*/
        4592,/*a2*a3*a4*/
        1968,/*a1*a3*a4*/
        861,/*a1*a2*a4*/
        336,/*a1*a2*a3*/
        112,/*a2*a3*/
        48,/*a1*a3*/
        21,/*a1*a2*/
        7,/*a2*/
        3,/*a1*/
        1
    };
    for (int k = 0; k < 16; ++k)
    {
        gap = incs[k];
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
                op++;
            }
            arr[j + gap] = temp;
            op++;
        }
    }
    return op;
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 获取当前时间的毫秒数
long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

// 测试希尔排序的正确性
void test1()
{
    int test_array[5][SHELL_LEN];

    // 产生随机序列
    srand(getCurrentTime());
    for (int i = 0; i < SHELL_LEN; i++)
    {
        test_array[0][i] = rand();
        for (int j = 1; j < 5; j++)
        {
            test_array[j][i] = test_array[0][i];
        }
    }
    printf("Original 排序前： ");
    print_array(test_array[0], SHELL_LEN);
    shell_sort(test_array[0], SHELL_LEN);
    printf("原始序列 排序后：  ");
    print_array(test_array[0], SHELL_LEN);

    printf("Hibbard 排序前：  ");
    print_array(test_array[1], SHELL_LEN);
    shell_sort_Hibbard(test_array[1], SHELL_LEN);
    printf("Hibbard 排序后：  ");
    print_array(test_array[1], SHELL_LEN);

    printf("Knuth 排序前：    ");
    print_array(test_array[2], SHELL_LEN);
    shell_sort_Knuth(test_array[2], SHELL_LEN);
    printf("Knuth 排序后：    ");
    print_array(test_array[2], SHELL_LEN);

    printf("Gonnet 排序前：   ");
    print_array(test_array[3], SHELL_LEN);
    shell_sort_Gonnet(test_array[3], SHELL_LEN);
    printf("Gonnet 排序后：   ");
    print_array(test_array[3], SHELL_LEN);

    printf("Sedgewick 排序前：");
    print_array(test_array[4], SHELL_LEN);
    shell_sort_Sedgewick(test_array[4], SHELL_LEN);
    printf("Sedgewick 排序后：");
    print_array(test_array[4], SHELL_LEN);
}

void test2()
{
    int test_array[5][SHELL_LEN];
    long shell_av = 0, hibb_av = 0, knu_av = 0, gon_av = 0, sedg_av = 0;
    for (int i = 0; i < ROUND; ++i)
    {
        // 产生随机序列
        srand(getCurrentTime());
        for (int k = 0; k < SHELL_LEN; k++)
        {
            test_array[0][i] = rand();
            for (int j = 1; j < 5; j++)
            {
                test_array[j][k] = test_array[0][k];
            }
        }

        long temp = shell_sort(test_array[0], SHELL_LEN);
        shell_av += temp;
        temp = shell_sort_Hibbard(test_array[1], SHELL_LEN);
        hibb_av += temp;
        temp = shell_sort_Knuth(test_array[2], SHELL_LEN);
        knu_av += temp;
        temp = shell_sort_Gonnet(test_array[3], SHELL_LEN);
        gon_av += temp;
        temp = shell_sort_Sedgewick(test_array[4], SHELL_LEN);
        sedg_av += temp;
    }
    shell_av /= ROUND;
    hibb_av /= ROUND;
    knu_av /= ROUND;
    gon_av /= ROUND;
    sedg_av /= ROUND;
    printf("shell_count: %ld\n", shell_av);
    printf("shell_sort_Hibbard: %ld\n", hibb_av);
    printf("shell_sort_Knuth: %ld\n", knu_av);
    printf("shell_sort_Gonnet: %ld\n", gon_av);
    printf("shell_sort_Sedgewick: %ld\n", sedg_av);
}

int main(int argc, char const *argv[])
{
    test2();
    return 0;
}
