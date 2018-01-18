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

int is_symmetric(BinTreeNode *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    // 前面已经判断过不会两个为空，那么这里只需判断一个为空即可返回 0
    if (root->left == NULL || root->right == NULL)
        return 0;
    if (root->left->data == root->right->data)
    {
        return is_symmetric(root->left) && is_symmetric(root->right);
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{

    return 0;
}
