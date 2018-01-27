/************************************
n个人围坐一圈，编号从1到n。依次从第一人开始，一人出去，留下一人;再出去2人，留下一人;...出去k人，留下一人;...直至所有人出完。给定n，最后出去的人编号是多少？编写程序实现:输入n，返回编号。
*/
#include <stdio.h>

//***********************************
static int get_last (int *k, int n)
{
    int i = *k;

    while (i < n)
    {
        n -= i;
        i++;
    }
    *k = i;//number of rounds to delete all
    return (n);//number of the last survivors
}

//***********************************
static int find_previous (int i, int n, int k)
{
    //index i in n survivors after deleting k
    while (k > 0)
    {
        n += k;
        i +=  k + 1;
        i %= n;
        if (i == 0)
            i = k;//skip one before deleting the next round
        k--;
    }
    return (i);
}

//***********************************
int main ()
{
    int n = 2018, i, j = 1;

    i = get_last (&j, n);
    // printf ("%d, %d\n", i, j);

    printf ("%d is the last to leave in %d\n", find_previous (i - 1, i, j - 1) + 1, n);

    return (0);
}

