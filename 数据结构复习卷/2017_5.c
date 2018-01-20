#include<stdio.h>

/**
 * @describe 获取 k^n 的十位数
 * @param k  底数
 * @param n  剩余次数
 * @param num  最后两位数
 * @return 十位数
 */
int get_tens_digit(int k, int n, int num)
{
    if (n == 0)
        return num/10;
    else
        return get_tens_digit(k, n - 1, (num * k) % 100);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", get_tens_digit(3, 3, 1));
    return 0;
}
