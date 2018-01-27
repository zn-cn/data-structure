#include<stdio.h>
#include<stdlib.h>
typedef struct Two_d_Tree
{
    int key1;
    int key2;
    struct Two_d_Tree* left;
    struct Two_d_Tree* right;
} two_d_Tree;

// 2-d 树的插入
two_d_Tree* insert(two_d_Tree* root, two_d_Tree* tree)
{
    if (root == NULL)
        return tree;
    int odd_even = 0;  // 0 代表偶数层， 1代表奇数层
    two_d_Tree* temp = root;
    while (temp != NULL)
    {
        // 偶数层，从第0层开始
        if (odd_even)
        {
            if (tree->key2 < temp->key2)
            {
                if (temp->left == NULL)
                {
                    temp->left = tree;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = tree;
                    break;
                }
                else
                    temp = temp->right;
            }
            odd_even = 0;
        }
        else
        {
            if (tree->key1 < temp->key1)
            {
                if (temp->left == NULL)
                {
                    temp->left = tree;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = tree;
                    break;
                }
                else
                    temp = temp->right;
            }
            odd_even = 1;
        }
    }
    return root;
}

/**
 * 高效打印满足 条件  low1 <= key1 <= high1, low2 <= key2 <= high2
 * @param root  根节点
 * @param low1  [description]
 * @param high1 [description]
 * @param low2  [description]
 * @param high2 [description]
 */
void print_keys(two_d_Tree* root, int low1, int high1, int low2, int high2)
{
    if (root != NULL)
    {
        if (root->key1 >= low1 && root->key1 <= high1 && root->key2 >= low2 && root->key2 <= high2)
            printf("(%d, %d)  ", root->key1, root->key2);
        print_keys(root->left, low1, high1, low2, high2);
        print_keys(root->right, low1, high1, low2, high2);
    }
}

int main()
{
    int test[10][2] = {{7, 2}, {5, 4}, {9, 6}, {2, 3}, {4, 7}, {8, 1}, {7, 7}, {1, 4}, {3, 5}, {8, 4}};
    two_d_Tree *head;
    two_d_Tree* temp = (two_d_Tree *) malloc(sizeof(two_d_Tree));
    temp->key1 = test[0][0];
    temp->key2 = test[0][1];
    head = insert(head, temp);

    for (int  i = 1;  i < 10; ++ i)
    {
        temp = (two_d_Tree *) malloc(sizeof(two_d_Tree));
        temp->key1 = test[i][0];
        temp->key2 = test[i][1];
        head = insert(head, temp);
    }

    print_keys(head, 3, 7, 4, 7);
    return 0;
}
