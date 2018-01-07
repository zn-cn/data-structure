/******************************************************************************
    FILENAME: radix.c
    DESCRIPTION: This file contains functions for radix sort
               using multiple rounds of bucket sorts.
         Local functions defined are:
                     bucket_init ()
                     bucket_free ()
                     bucket_sort ()
                     radix_sort ()
    AUTHOR: Gang Shen
    CREATED ON: 2009/12/26
    REVISION HISTORY:
      Initial version - 2009/12/26
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//#include <string.h>

/******************************************************************************
*/
#define SUCCESS (0)
#define FAILURE (-1)
#define NUM_ENTRIES(a)    ((sizeof (a)) / (sizeof (a[0])))
#define DEBUG

/******************************************************************************
*/
typedef struct nODE
{
    int data;
    struct nODE *next;
} NODE;

typedef struct bUCKET
{
    NODE *head;
    NODE *rear;
} BUCKET;

/******************************************************************************
*/
static int bucket_init (int radix, BUCKET **bucket);
static int bucket_sort (int a[], int n, int k, int radix, BUCKET *bucket);
static int bucket_free (BUCKET *bucket);
static int radix_sort (int a[], int n, int radix);

/******************************************************************************
    bucket_init () - this function craetes radix buckets, each bucket
                     maintains pointers to a queue's head and rear
                     pointers, initialzed to NULL
    Inputs: radix - int, number of buckets
           bucket - BUCKET **, pointer to a bucket array's address
    Outputs: bucket - BUCKET **, pointer to a bucket array's address
    Returns: FAILURE - invalid radix, or malloc failure
             SUCCESS - otherwise
*/
static int bucket_init (int radix, BUCKET **bucket)
{
    if (radix < 1)
    {
        printf ("invalid radix %d, should be greater than 0\n", radix);
        return (FAILURE);
    }

    *bucket = (BUCKET *)malloc (sizeof (BUCKET) * radix);
    if (*bucket == NULL)
    {
        printf ("malloc () failed\n");
        return (FAILURE);
    }
    memset ((char *)*bucket, 0, sizeof (BUCKET) * radix);
    return (SUCCESS);
}

/******************************************************************************
    bucket_free () - release memory allocated to the bucket array
    Inputs: bucket - BUCKET *, bucket array
    Outputs: none
    Returns:
*/
static int bucket_free (BUCKET *bucket)
{
    free (bucket);
    return (SUCCESS);
}

/******************************************************************************
    bucket_sort () - does a round of bucket sort with initialized buckets
                     on an array by inserting entries into the queue of the
                     matching bucket, and then dump into the array
    Inputs: a - int *, array to sort
            n - int, length of a
            k - int, number of the current round for bucket sort
            radix - int, radix used in sort
            bucket - BUCKET *, pointer to buckets
    Outputs: a - sorted array
*/
static int bucket_sort (int a[], int n, int k, int radix, BUCKET *bucket)
{
    int i, j, key;
    NODE *node;

    for (i = 0; i < n; i++)
    {
        for (j = 0, key = a[i]; j < k; j++)
        {
            key = key / radix;
        }
        key = key % radix;
        node = (NODE *)malloc (sizeof (NODE));
        if (node == NULL)
        {
            printf ("malloc () failed, bucket_sort () aborted\n");
            return (FAILURE);
        }
        node->data = a[i];
        node->next = NULL;
        if (bucket[key].head == NULL)
        {
            bucket[key].head = node;
            bucket[key].rear = node;
        }
        else
        {
            bucket[key].rear->next = node;
            bucket[key].rear = node;
        }
    }

    for (i = 0, j = 0; i < radix; i++)
    {
        while (bucket[i].head != NULL)
        {
            a[j++] = bucket[i].head->data;
            node = bucket[i].head;
            bucket[i].head = bucket[i].head->next;
            free (node);
        }
    }

#ifdef DEBUG
    for (i = 0; i < n; i++)
    {
        printf ("%d, ", a[i]);
    }
    printf ("\n");
#endif
    return (SUCCESS);
}

/******************************************************************************
    radix_sort () - does radix sort on an array with mulptiple bucket sorts
    Inputs: a - int *, array to sort
            n - int, length of the array
            radix - int, radix of bucket sort
    Outputs: a - int *, sorted array
    Returns:
*/
static int radix_sort (int a[], int n, int radix)
{
    BUCKET *bucket;
    int i, j, k, m;

    if (bucket_init (radix, &bucket) != SUCCESS)
    {
        printf ("bucket_init () failed\n");
        return (FAILURE);
    }

#ifdef DEBUG
    printf ("original array is: ");
    for (i = 0; i < n; i++)
    {
        printf ("%d, ", a[i]);
    }
    printf ("\n");
#endif

    for (i = 0, j = 0, k = 0, m = 0; i < n; i++)
    {
        for (j = 0, k = a[i]; k > 0; j++)
        {
            k /= radix;
        }
        if (j > m)
            m = j;
    }
#ifdef DEBUG
    printf ("need %d rounds of bucket sort\n", m);
#endif

    for (i = 0; i < m; i++)
    {
        if (bucket_sort (a, n, i, radix, bucket) != SUCCESS)
        {
            printf ("bucket_sort () failed\n");
            return (FAILURE);
        }
    }
    bucket_free (bucket);
    return (SUCCESS);
}

/******************************************************************************
*/
static int a[] = {12, 129, 230, 342, 22, 155, 76, 98, 339, 1000, 876, 581, 703};

int main ()
{
    radix_sort (a, NUM_ENTRIES (a), 10);

    return (SUCCESS);
}

