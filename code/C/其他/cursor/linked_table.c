#include<stdio.h>

/*链表的游标实现的声明*/
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef char ElementType;
#define SPACE_SIZE 11

void initialize_cursor_space( void );
Position cursor_alloc( void );
void cursor_free( Position p );
int is_empty( List L );
int is_last( List L, Position p );
Position find( ElementType X, List L );
Position find_previous( List L, ElementType X);
void delete( List L, ElementType X );
void insert( Position p, ElementType X );


struct Node {
    ElementType Element;
    Position Next;
};
struct Node cursor_space[ SPACE_SIZE ];

/*cursor_space的初始化*/
void initialize_cursor_space( void )
{

    for (int i = 0; i <= SPACE_SIZE - 1; i++)
    {
        // cursor_space[i].Element = 0;
        cursor_space[i].Next = i + 1;
    }
    cursor_space[ SPACE_SIZE - 1 ].Next = 0;
}

/*cursor_alloc*/
Position cursor_alloc( void )
{
    Position p;
    p = cursor_space[0].Next;
    cursor_space[0].Next = cursor_space[p].Next;
    return p;  // 返回开辟空间，0永远指向空余空间
}
/*cursor_free*/
void cursor_free( Position p )
{
    cursor_space[p].Next = cursor_space[0].Next;
    cursor_space[0].Next = p;
}
/*测试链表为空*/
/*return true if L is empty */
int is_empty( List L )
{
    return cursor_space[L].Next == 0;
}
/*测试p是不是链表的末尾*/
/*return true if p is the last position in list L*/
int is_last( List L, Position p )
{
    return cursor_space[p].Next == 0;
}
/*find游标实现*/
/* return position of X in L,0 is not found */
/* use a header node */
Position find( ElementType X, List L )
{
    Position p;
    p = cursor_space[L].Next;
    while ( p != 0 && cursor_space[p].Element != X)
        p = cursor_space[p].Next;
    return p;
}
/*find_previous*/
Position find_previous( List L, ElementType X)
{
    Position p;
    p = L;
    while (cursor_space[p].Next != 0 && cursor_space[cursor_space[p].Next].Element != X)
        p = cursor_space[p].Next;
    return p;
}

/* 对链表进行删除操作 */
/* delete first occurrence of X */
/* assume header node */
void delete( List L, ElementType X )
{
    Position p, TmpCell;
    p = find_previous(L, X);
    if (!is_last(L, p))
    {
        TmpCell = cursor_space[p].Next;
        cursor_space[p].Next = cursor_space[TmpCell].Next;
        cursor_free(TmpCell);
    }

}
/* 对链表进行插入操作 */
/*insert after position p */
/* header assumed */
/* L is not used */
void insert( Position p, ElementType X )
{
    Position TmpCell;
    TmpCell = cursor_alloc();
    if (TmpCell == 0) //当freelist为只有表头的空表会返回0
        printf("Out of Space\n");

    cursor_space[TmpCell].Element = X;
    cursor_space[TmpCell].Next = cursor_space[p].Next;
    cursor_space[p].Next = TmpCell;
}

int main(int argc, char const *argv[])
{
    initialize_cursor_space();
    Position position = cursor_alloc();
    printf("%d\n", position);
    cursor_space[position].Element = 'b';
    position = cursor_alloc();
    printf("%d\n", position);
    cursor_space[position].Element = 'c';

    return 0;
}
