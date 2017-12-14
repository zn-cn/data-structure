#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
#define NULL    (0)
#endif

#define dEBUG
//***********************************
typedef struct nODE {
    int data;
    struct nODE *next;
} NODE;

//**********************************
static void delete_list (NODE *list) {
    NODE *ptr;

    while (list != NULL) {
        ptr = list->next;
        free (list);
        list = ptr;
    }

    return;
}

//***********************************
static NODE *reverse (NODE *list) {
#ifdef dEBUG
    NODE *ptr = list->next;

    // only one node
    if (ptr == NULL) {
        return (list);
    }

    (reverse (list->next))->next = list;

    return (list);
#else
    NODE *tmp1 = NULL, *tmp2 = NULL;

    while (list != NULL) {
        tmp2 = list->next;

        list->next = tmp1;
        tmp1 = list;
        list = tmp2;
    }

    return (tmp1);
#endif
}

//**********************************
static NODE *create_list (int size) {
    NODE *list, *ptr, *tmp = NULL;
    int i;

    list = (NODE *)malloc (sizeof (NODE));

    if (list == NULL) {
        printf ("malloc () faile\n");
        return (NULL);
    }

    for (i = 0; i < size; i++) {
        ptr = (NODE *)malloc (sizeof (NODE));

        if (ptr == NULL) {
            printf ("malloc () failed\n");
            return (NULL);
        }
        ptr->data = size - i;
        ptr->next = tmp;
        tmp = ptr;
    }
    list->next = tmp;
    while (tmp != NULL) {
        printf ("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf ("\n");

    return (list);
}

//**********************************
int main () {
    int i, size = 20;
    NODE *list, *ptr, *pre, *tmp;

    list = create_list (size);
    if (list == NULL)
        exit (-1);

    for (i = 0; i < 2; i++) {
#ifdef dEBUG
        tmp = list->next;
        if (tmp == NULL)
            exit (0);
        //find the end of the list
        tmp = tmp->next;
        while (tmp != NULL) {
            pre = tmp;
            tmp = tmp->next;
        }
        ptr = reverse (list->next);
        ptr->next = NULL;
        tmp = pre;
        list->next = tmp;
#else
        tmp = reverse (list->next);
        list->next = tmp;
#endif

        while (tmp != NULL) {
            printf ("%d->", tmp->data);
            tmp = tmp->next;
        }
        printf ("\n");
    }
    delete_list (list);

    exit (0);
}
