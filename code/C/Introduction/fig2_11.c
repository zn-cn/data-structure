#include <stdio.h>

#define IsEven( N ) ( ( N ) % 2 == 0 )

/* START: fig2_11.txt */
long int Pow( long int X, unsigned int N )
{
    if ( N == 0 )
        return 1;
    if ( N == 1 )
        return X;
    if ( IsEven( N ) )
        return Pow( X * X, N / 2 );
    else
        return Pow( X * X, N / 2 ) * X;
}
/* END */

int main( )
{
    printf( "2^21 = %ld\n", Pow( 2, 21 ) );
    return 0;
}
