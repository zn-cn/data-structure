#include <stdio.h>
// 定义长度
#define NUM_OF_ENTRIES(a)    (sizeof (a))/(sizeof (a[0]))

//define a tree using cursors
typedef struct tREE
{
  int data;
  int left;
  int right;
} TREE;

//test case: modify to test different paths
static TREE tr[] =
{
  {10, 1, 2},
  {5, -1, 3},
  {15, 6, 5},
  {8, 4, -1},
  {6, -1, -1},
  {22, -1, -1},
  {12, 7, -1},
  {11, -1, -1},
  {80, -1, -1},
  {2, -1, -1},
  {88, -1, -1},
  {18, -1, -1},
};

//中根输出
static void traverse (int root)
{
  if (root == -1)
    return;

  traverse (tr[root].left);
  printf ("%d\n", tr[root].data);
  traverse (tr[root].right);

  return;
}

//计算节点数
static int count_nodes (int root)
{
  if (root == -1)
    return (0);

  return (1 + count_nodes (tr[root].left) + count_nodes (tr[root].right));
}

//插入
static int insert (int root, int i)
{
  if (root < 0)
  {
    return (i);
  }

  if (tr[i].data < tr[root].data)
    tr[root].left =  insert (tr[root].left, i) ;
  else if (tr[i].data > tr[root].data)
    tr[root].right = insert (tr[root].right, i) ;

  return (root);
}

//找到最小的节点
static int find_min (int root)
{
  if (tr[root].left < 0)
    return (root);

  return (find_min (tr[root].left));
}

//删除节点i
static int delete (int root, int i)
{
  int tmp;

  if (root < 0)
    return (-1);

  if (tr[i].data < tr[root].data)
    tr[root].left = delete (tr[root].left, i);
  else if (tr[i].data > tr[root].data)
    tr[root].right = delete (tr[root].right, i);
  else if (tr[root].left > 0 && tr[root].right > 0)
  {
    tmp = find_min (tr[root].right);
    tr[root].data = tr[tmp].data;
    tr[root].right = delete (tr[root].right, tmp);
  }
  else if (tr[root].left > 0)
    return (tr[root].left);
  else
    return (tr[root].right);

  return (root);
}


int main ()
{
  int i;

  traverse (0);
  printf ("now we have %d nodes\n", (i =  count_nodes (0)));

  for (; i < NUM_OF_ENTRIES (tr); i++)
  {
    insert (0, i);
  }

  printf ("after insertions\n");

  for (i = 0; i < NUM_OF_ENTRIES (tr); i++)
    printf ("{%d, %d, %d}\n", tr[i]. data, tr[i].left, tr[i].right);

  for (i = 5; i < NUM_OF_ENTRIES (tr); i++)
    delete (0, i);

  printf ("after deletions\n");
  for (i = 0; i < NUM_OF_ENTRIES (tr); i++)
    printf ("{%d, %d, %d}\n", tr[i]. data, tr[i].left, tr[i].right);

  traverse (0);

  return (0);
}
