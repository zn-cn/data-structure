/*
    原版分离链路法
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode;
typedef struct ListNode *position;
typedef position list;
struct HashTable;
typedef struct HashTable *hashTable;
typedef int ElementType;
#define MINTABLESIZE 5
#define MAXTABLESIZE 20


hashTable initializeTable(int tablesize);
void destroyTable(hashTable H);
position find(ElementType key, hashTable H);
ElementType retrieve(position p);
int nextPrime(int tableSize);
int isPrime(int x);
void insert(ElementType key, hashTable H);
int Hash(ElementType key, int tableSize);
int Delete(ElementType key, hashTable H);

struct ListNode
{
    ElementType element;
    position next;
};

struct HashTable
{
    int tableSize;
    list *thelists; //指向ListNode的指针的指针
};

hashTable initializeTable(int tableSize)
{
    hashTable H;
    int i;

    if (tableSize < MINTABLESIZE)
    {
        printf("table is too small!\n");
        return NULL;
    }
    H = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (H == NULL)
    {
        printf("out of space\n");
        return NULL;
    }
    H->tableSize = nextPrime(tableSize); //11

    //创建指针数组
    H->thelists = (list*)malloc(sizeof(list) * H->tableSize); //指针数组,数组里不放数据，数据放在链表里

    if (H->thelists == NULL)
    {
        printf("out of space!\n");
        return NULL;
    }
    //创建指针数组元素指向的链表表头
    for (i = 0; i < H->tableSize; i++)
    {
        H->thelists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (H->thelists[i] == NULL)
        {
            printf("out of space!\n");
            return NULL;
        }
        else
            H->thelists[i]->next = NULL;
    }
    return H;
}

int nextPrime(int tableSize)
{
    while (1)
    {
        if (isPrime(tableSize))
            return tableSize;
        else
            tableSize++;
    }
}
int isPrime(int x)
{
    int i;
    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void destroyTable(hashTable H)
{
    position h, p, q;
    int i;
    for (i = 0; i < H->tableSize; i++)
    {
        h = H->thelists[i];
        p = h->next;
        while (p)
        {
            q = p->next;
            if (!q)
            {
                free(p);
                p = NULL;
            }
            else
            {
                free(p);
                p = q;
            }
        }
    }
}

position find(ElementType key, hashTable H)
{
    position p;
    list L;

    L = H->thelists[Hash(key, H->tableSize)];
    p = L->next;
    while (p)
    {
        if (p->element == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void insert(ElementType key, hashTable H)
{
    position pos, newcell;
    list L;

    pos = find(key, H);
    if (pos == NULL) //错把pos=null当作判断条件，此条件永远为真。
    {
        newcell = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newcell == NULL)
        {
            printf("out of space\n");
            exit(-1);
        }
        else
        {
            L = H->thelists[Hash(key, H->tableSize)];
            newcell->next = L->next;
            newcell->element = key;
            L->next = newcell;
        }
    }
}

int Hash(ElementType key, int tableSize)
{
    return key % tableSize;
}

int Delete(ElementType key, hashTable H)
{
    position pos, h, L;
    L = H->thelists[Hash(key, H->tableSize)];
    h = L;
    while (h != NULL && h->next && h->next->element != key)
        h = h->next;

    if (h == NULL || h->next == NULL)
    {
        printf("cant find that key!\n");
        return 0;
    }
    else
    {
        pos = h->next;
        h->next = pos->next;
        free(pos);
        return 1;
    }
}

ElementType retrieve(position p)
{
    return p->element;
}

void test()
{
    hashTable table;
    position p;

    table = initializeTable(10);


    insert(0, table);
    insert(1, table);
    insert(81, table);
    insert(4, table);
    insert(64, table);
    insert(25, table);
    insert(16, table);
    insert(36, table);
    insert(9, table);
    insert(49, table);


    p = find(81, table);
    if (p == NULL)
        printf("cant find 1\n");
    else
        printf("find %d \n", p->element);

    if (Delete(81, table))
    {
        printf("Delete 81\n");
    }

    p = find(81, table);
    if (p == NULL)
        printf("cant find 81\n");
    else
        printf("find %d \n", p->element);

    destroyTable(table);

}

int main()
{
    test();
}
