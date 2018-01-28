#include <stdio.h>

/* START: fig2_10.txt */
unsigned int Gcd( unsigned int M, unsigned int N )
{
    unsigned int Rem;

    while ( N > 0 )
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}
/* END */

int main( )
{
    printf( "Gcd( 45, 35 ) = %d\n", Gcd( 45, 35 ) );
    printf( "Gcd( 1989, 1590 ) = %d\n", Gcd( 1989, 1590 ) );
    return 0;
}
