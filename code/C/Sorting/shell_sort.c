#include<stdio.h>

static int count = 0;
void swap(int *array, int i, int k) {
    int temp = array[i];
    array[i] = array[k];
    array[k] = temp;
}

void shellSort(int *array, int length) {
    int gap = length / 2;
    while (gap > 0) {
        for (int i = gap; i < length; i++) {
            for (int j = i; gap <= j; j -= gap) {
                count++;
                if (array[j - gap] > array[j]) {
                    swap(array, j - gap, j);
                } else {
                    break;
                }
            }
        }
        gap = gap / 2;
    }
}

int main(int argc, char const *argv[])
{
    int test[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    shellSort(test, 15);
    printf("count: %d\n", count);
    for (int i = 0; i < 15; ++i)
    {
        printf("%d\n", test[i]);
    }
    return 0;
}

