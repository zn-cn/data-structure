#include<stdio.h>

int find_previous(int n)
{
    // 初始化
    int array[n];
    for (int i = 0; i < n; ++i)
    {
        array[i] = i + 1;
    }

    int currentNode = 0;
    int rest = n;
    int k = 1;
    while (rest != 0)
    {
        // 出去k 个人
        for (int i = 0; i < k; ++i)
        {
            while (array[currentNode] == 0)
            {
                currentNode = (currentNode + 1)%n;
            }

            array[currentNode] = 0;
            rest--;
            if (rest == 0)
            {
                return currentNode + 1;
            }
            currentNode = (currentNode + 1)%n;

        }

        // 留下一人
        while (array[currentNode] == 0)
        {
            currentNode = (currentNode + 1)%n;
        }
        currentNode = (currentNode + 1)%n;
        k++;
    }
    return currentNode + 1;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", find_previous(2018));
    return 0;
}
