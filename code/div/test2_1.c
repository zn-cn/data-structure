#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *b,*c;
    int a;
    a=1;
    b=a;
    *c=a;
//    printf("%u,%d",&a,a);
    printf("%u,%d",b,*b);
    return 0;
}

