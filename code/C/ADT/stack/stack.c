#include <stdio.h>

#define MAX_SIZE    (100)
//***********************************
static char stk[MAX_SIZE];
static int top = -1;

#define IS_empty    (top == -1)
#define IS_full     (top == (MAX_SIZE - 1))
#define Push(x)    stk[++top] = (x)
#define Pop    (stk[top--])

//***********************************
static int check (char *expn)
{
	char *ptr = expn, c;
	
	while (*ptr != '\0')
	{
		if (*ptr ==  '(' || *ptr == '[' || *ptr == '{')
		{
			if (IS_full)
			{
				printf (" stack full\n");
				return (-1);
			}
		    Push (*ptr);
		}
		else if (*ptr == ')' || *ptr == ']' || *ptr == '}')
		{
			if (IS_empty)
		    {
		    	printf ("unblanced with outstanding closing bracket\n");
		    	return (0);
		    }
		    c = Pop;
		    if ((c == '(' && *ptr != ')') ||
		         (c == '[' && *ptr != ']') ||
		         (c == '{' && *ptr != '}') )
		    {
		        printf (" unbalanced with mismatched bracket\n");
		    	return (0);
		    }
		 }       
	     ptr++;		
	}
	
	if (!IS_empty)
	{
	    printf ("unblanced with outstanding openning bracket\n");
	    return (0);
	}
	    
	printf ("balanced\n");
	return (0);
}

//***********************************
static char expr[] = "1(2[3{!}])";

int main ()
{
	check (expr);
}