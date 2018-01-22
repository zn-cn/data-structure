#include<stdio.h>

void bucket_sort(int *data, int len, int min, int max)
{
    int buckets[max - min + 1];
    for (int i = 0; i < max - min + 1; ++i) {
        buckets[i] = 0;
    }
    for (int i = 0; i < len; ++i)
    {
        buckets[data[i] - min] += 1;
    }
    for (int i = 0, j = 0; i < max - min + 1; ++i)
    {
        if (buckets[i] != 0)
        {
            for (int k = 0; k < buckets[i]; ++k)
            {
                data[j++] = i + min;
            }

        }
    }
}

int main(int argc, char const *argv[])
{
    int data[] = { 5, 3, 6, 2, 1, 9, 4, 8, 7, 4, 3, 8 };

    for (int i = 0; i < 12; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    bucket_sort(data, 12, 1, 9);

    for (int i = 0; i < 12; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
