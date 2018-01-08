/*
    pdf要求的分离链路法, 第一种 ElementType 为 int 型
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode;
typedef struct ListNode *position;
typedef position list;
struct HashTable;
typedef struct HashTable *hashTable;
typedef int ElementType;

hashTable initializeTable(int tablesize);
void destroyTable(hashTable H);
position find(ElementType key, hashTable H);
void insert(ElementType key, hashTable H);
int Hash(ElementType key, int tableSize);
int Delete(ElementType key, hashTable H);
void extend(hashTable H);
int cal_k(int n);

struct ListNode
{
    ElementType element;
    position next;
};

struct HashTable
{
    int tableSize;
    int cur_size;    // 当前已经填入的元素的个数，如果 X 为10， 1和81算一个
    list *thelists; //指向ListNode的指针的指针
};

hashTable initializeTable(int tableSize)
{
    if ((1 << cal_k(tableSize)) - 1  != tableSize)
    {
        printf("你输入的大小有误，必须为2的k次方 -1 \n");
        return NULL;
    }
    hashTable H;
    int i;
    H = (hashTable)malloc(sizeof(struct HashTable));
    if (H == NULL)
    {
        printf("out of space\n");
        return NULL;
    }
    H->tableSize = tableSize;
    H->cur_size = 0;

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
    free(H);
}

position find(ElementType key, hashTable H)
{
    position p;
    list L;

    L = H->thelists[Hash(key, H->tableSize)];
    if (L == NULL)
        return NULL;
    p = L->next;
    while (p && p->element != key)
    {
        p = p->next;
    }
    return p;
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
            if (L->next == NULL)
                H->cur_size++;
            newcell->next = L->next;
            newcell->element = key;
            L->next = newcell;

            if (H->cur_size * 1.0 / H->tableSize >= 0.75)
            {

                extend(H);
            }
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

// 扩展hash表的大小
void extend(hashTable H)
{
    int k = cal_k(H->tableSize);
    H->tableSize = (1 << (k + 1)) - 1;
    list* pre = H->thelists;
    H->thelists = (list*)malloc(sizeof(list) * H->tableSize);
    for (int i = 0; i < H->tableSize; i++)
    {
        H->thelists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
    }
    for (int i = 0; i < (1 << k) - 1; ++i)
    {
        list temp = pre[i]->next;
        while (temp != NULL)
        {
            insert(temp->element, H);
            list temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }

}

int cal_k(int n)
{
    int k = 0;
    for ( ; ((1 << k) - 1) < n; ++k)
        ;
    return k;
}

void test()
{

    hashTable table;
    position p;

    table = initializeTable(15);

    insert(0, table);
    insert(1, table);
    insert(81, table);
    insert(6, table);
    insert(4, table);
    insert(64, table);
    insert(25, table);
    insert(16, table);
    insert(36, table);
    insert(9, table);
    insert(49, table);
    insert(2, table);
    insert(3, table);
    insert(7, table);
    insert(8, table);
    insert(10, table);
    insert(11, table);
    insert(12, table);
    insert(13, table);
    insert(14, table);


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
