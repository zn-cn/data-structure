#include<stdio.h>

/*
9.编写一个C语言函数int count_nodes(BinTreeNode *root)返回以root为根的二叉树中节点的个数。
 */

typedef struct binTreeNode
{
	int data;
	struct binTreeNode *left;
	struct binTreeNode *right;
} BinTreeNode;

int count_nodes(BinTreeNode *root)
{
	if (root == NULL)
		return 0;
	else
		return count_nodes(root->left) + 1 + count_nodes(root->right);
}

int main(int argc, char const *argv[])
{

	return 0;
}
