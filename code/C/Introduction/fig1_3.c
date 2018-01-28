#include <stdio.h>

/* START: fig1_3.txt */
int Bad( unsigned int N )
{
    if ( N == 0 )
        return 0;
    else
        return Bad( N / 3 + 1 ) + N - 1;
}
/* END */

int main( )
{
    printf( "Bad is infinite recursion\n" );
    return 0;
}
