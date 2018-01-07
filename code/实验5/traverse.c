#include <stdlib.h>
#include <stdio.h>

typedef struct TNode
{
    int val;
    TNode* left;
    TNode* right;
} TNode, *BTree;

//根据先序遍历、中序遍历构建二叉树
BTree rebuild(int preOrder[], int startPre, int endPre, int midOrder[], int startIn, int endIn)
{
    //起始位置不应大于末尾位置,先序遍历和中序遍历长度应相等
    if (endPre - startPre != endIn - startIn || startPre > endPre)
        return NULL;
    //先序遍历的第一个元素为根节点
    BTree tree = (BTree)malloc(sizeof(TNode));
    tree->val = preOrder[startPre];
    tree->left = NULL;
    tree->right = NULL;

    //先序遍历和中序遍历只有一个元素时，返回该节点
    if (startPre == endPre)
        return tree;
    //在中序遍历中找到根节点
    int index, length;
    for (index = startIn; index <= endIn; index++)
    {
        if (midOrder[index] == preOrder[startPre])
            break;
    }
    //若未找到，返回空
    if (index > endIn)
        return NULL;
    //有左子树，递归调用构建左子树
    if (index > startIn)
    {
        length = index - startIn;
        tree->left = rebuild(preOrder, startPre + 1, startPre + 1 + length - 1, midOrder, startIn, startIn + length - 1);
    }
    //有右子树，递归调用构建右子树
    if (index < endIn)
    {
        length = endIn - index;
        tree->right = rebuild(preOrder, endPre - length + 1, endPre, midOrder, endIn - length + 1, endIn);
    }
    return tree;
}

//后序遍历二叉树
void lastTraverse(BTree tree)
{
    if (tree->left != NULL)
        lastTraverse(tree->left);

    if (tree->right != NULL)
        lastTraverse(tree->right);
    printf("%d ", tree->val);
}

int main()
{
    int preOrder[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int midOrder[] = {8, 4, 9, 2, 5, 1, 6, 3, 7};
    BTree tree = rebuild(preOrder, 0, 8, midOrder, 0, 8);
    lastTraverse(tree);
    printf("\n");
    return 0;
}
