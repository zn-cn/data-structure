

#include <stdio.h>

//***********************************
static int max_subseq (int a[], int n);
static int both_sides (int a[], int n);

//***********************************
static int max_subseq (int a[], int n)
{
	int m1, m2, m;
	
	//exit of the recursion
	//either only one element in array
	//or empty array
	if (n == 1)
	    return (a[0]);
	if (n == 0)
	    return (-1);
	    
	//recursive parts
	//recursion on the first half
	m1 = max_subseq (a, (n+1)/2);
	//recursion on the second half
	m2 = max_subseq (&a[(n+1)/2], n - (n+1)/2);
	
	//non-recursive part
	//max achieved across both halves
	m = both_sides (a, n);
	
	//take the max of three
	if (m1 > m2)
	{
		if (m1 > m)
		    return (m1);
	}
	else
	{
		if (m2 > m)
			return (m2);
	}
	
	return (m);
}

//***********************************
static int both_sides (int a[], int n)
{
	int i, j = (n+1)/2;
	int m1 = 0,  m2 = 0;
	int cur = 0;
	
	//j is the length of the first half
	//first half: moving backward
	for (i = j - 1; i >= 0; i--)
	{
		cur += a[i];
		if (cur > m1)
		    m1 = cur;
	}
	
	//second half, reset temp, move forward
	cur = 0;
	for (i = j; i < n; i++)
	{
		cur += a[i];
		if (cur > m2)
		    m2 = cur;
	}
	
	return (m1 + m2);
}

//***********************************
static int aa[8] = {1,-2,3,4,-5,6,-7,8};

int main ()
{
	printf ("maximum of the subsequence sums is %d\n", max_subseq (aa, 8));
}