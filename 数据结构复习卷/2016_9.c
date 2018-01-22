#include<stdio.h>
/*
编程一个C语言函数 int is_symmetric(BinTreeNode *root) 判断一棵以root为根的二叉树
是否对称（左右子树完全相等），如果是则返回1，否则返回0。
 */
typedef struct binTreeNode
{
    int data;
    struct binTreeNode *left;
    struct binTreeNode *right;
} BinTreeNode;

int symmetric(BinTreeNode *left, BinTreeNode *right)
{
    if (left == NULL && right == NULL)
        return 1;
    else
        if (left == NULL || right == NULL)
            return 0;
        else
            return (left->data == right->data) && symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

int is_symmetric(BinTreeNode *root)
{
    if (root == NULL)
        return 1;
    return symmetric(root->left, root->right);
}

int main(int argc, char const *argv[])
{
    return 0;
}
