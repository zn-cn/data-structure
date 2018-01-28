#include <stdio.h>

/* START: fig1_2.txt */
int F( int X )
{
    if ( X == 0 )
        return 0;
    else
        return 2 * F( X - 1 ) + X * X;
}
/* END */

int main( )
{
    printf( "F(5) = %d\n", F( 5 ) );
    return 0;
}
