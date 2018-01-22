#include<stdio.h>

// 找到第五大的数字
int get_fifth_num(int* arr, int len)
{
    if (len < 5)
        NULL;

    // 存储前五大数字
    int fifth_array[5];
    for (int i = 0; i < 5; ++i)
    {
        fifth_array[i] = arr[i];
    }

    // 首先将前五数字排序
    for (int i = 0; i < 4; i++)
    {
        for (int j = 4; j > i; j--)
        {
            if (fifth_array[i] < fifth_array[j])
            {
                int temp = fifth_array[i];
                fifth_array[i] = fifth_array[j];
                fifth_array[j] = temp;
            }
        }
    }

    for (int i = 5; i < len; ++i)
    {
        // 若数组中的数字大于 fifth_array中最小的数字则插入
        if (arr[i] > fifth_array[4])
        {
            // 插入
            fifth_array[4] = arr[i];
            for (int j = 3; j >= 0; j--)
            {
                if (fifth_array[j] < fifth_array[j + 1])
                {
                    int temp = fifth_array[j];
                    fifth_array[j] = fifth_array[j + 1];
                    fifth_array[j + 1] = temp;
                }
                else
                    break;
            }
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("%d  ", fifth_array[i]);
    }
    return fifth_array[4];
}


int main(int argc, char const *argv[])
{
    int arr[15] = {1, 5, 3, 4, 6, 89, 67, 34, 2, 5, 4, 56, 24, 56, 67};
    int result = get_fifth_num(arr, 15);
    printf("\n第五大的数字： %d\n", result);
    return 0;
}
