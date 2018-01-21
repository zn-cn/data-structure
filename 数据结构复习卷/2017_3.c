#include<stdio.h>

/*
编写C语言函数 int is_index(int a[], int n) 判断升序排列的整数数组a（长度为n）中
是否存在a[i] = i；如果存在，返回TRUE，否则返回FALSE。说明程序的时间复杂度是多少。
 */
// 顺序求解
int is_index(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		if (a[i] == i)
			return 1;
	return 0;
}

int get_res(int a[], int first, int last)
{
	if ((last - first) == 0)
		if (a[first] == first)
			return 1;
		else
			return 0;
	else if (a[(first + last) / 2] < (first + last) / 2)
		return get_res(a, (first + last) / 2 + 1, last);
	else
		return get_res(a, first, (first + last) / 2);
}

// 分治算法求解
int is_index2(int a[], int n)
{
	return get_res(a, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	int a[5] = {1, 2, 3, 4, 5};
	printf("%d\n", is_index2(a, 5));
	return 0;
}
