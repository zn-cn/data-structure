#include<stdio.h>
#include<time.h>

int getMain_elementByViolent(int* array, int len);
int getMain_element2(int* array, int len);

int main(int argc, char const *argv[])
{
    int array[30] = {1, 1, 1, 2, 2, 2, 1, 2, 3, 4, 0, 2, 5, 6, 7, 9, 10, 34, 6, 7, 4, 9, 22, 56, 23, 12, 67, 23, 67, 89};

    double cpu_time;
    clock_t a, b;

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 100000; ++i)
        {
            getMain_elementByViolent(array, 30);
        }

        b = clock();

        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒


        printf("method one time: %f ms\n", cpu_time);
    }
    printf("\n");

    for (int j = 10; j < 20; ++j)
    {
        a = clock();
        for (int i = 0; i < 100000; ++i)
        {
            getMain_element2(array, 30);
        }

        b = clock();

        cpu_time = ((double)(b - a)) / 1000; // 转换为毫秒


        printf("method two time: %f ms\n", cpu_time);
    }
    printf("\n");

    return 0;
}

int getMain_elementByViolent(int* array, int len)
{
    for (int i = 0; i < len; ++i)
    {
        int num = 0;
        for (int j = 0; j < len; ++j)
        {
            if (array[i] == array[j])
            {
                num++;
            }
        }

        if (num > len / 2)
        {
            return array[i];
        }
    }
    return 0;
}

int getMain_element2(int* array, int len)
{
    // 寻找候选元
    int candidate[len / 2];
    int n = 0;
    for (int i = 0; i < len - 1; i = i + 2)
    {
        if (array[i] == array[i + 1])
        {
            candidate[n] = array[i];
            n++;
        }
    }

    for (int i = 0; i < len / 2; ++i)
    {
        if (candidate[i] == 0)
        {
            break;
        }
        else
        {
            int num = 0;
            for (int j = 0; j < len; ++j)
            {
                if (array[j] == candidate[i])
                {
                    num++;
                }
            }

            if (num > len / 2)
            {
                return candidate[i];
            }
        }
    }

    return 0;
}
