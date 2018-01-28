#include <stdio.h>

typedef int ElementType;
#define NotFound (-1)

/* START: fig2_9.txt */
int BinarySearch( const ElementType A[ ], ElementType X, int N )
{
    int Low, Mid, High;

    Low = 0; High = N - 1;
    while ( Low <= High )
    {
        Mid = ( Low + High ) / 2;
        if ( A[ Mid ] < X )
            Low = Mid + 1;
        else if ( A[ Mid ] > X )
            High = Mid - 1;
        else
            return Mid;  /* Found */
    }
    return NotFound;     /* NotFound is defined as -1 */
}
/* END */

int main( )
{
    static int A[ ] = { 1, 3, 5, 7, 9, 13, 15 };
    const int SizeofA = sizeof( A ) / sizeof( A[ 0 ] );
    int i;

    for ( i = 0; i < 20; i++ )
        printf( "BinarySearch of %d returns %d\n",
                i, BinarySearch( A, i, SizeofA ) );
    return 0;
}
