#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Tree
{
    int val;
    struct Tree* left;
    struct Tree* right;
} tree;

//判断两棵树是否同构
bool judge_iso(tree* first, tree* second) {
    if ((first == NULL) && (second == NULL))
        return true;
    if (((first == NULL) && (second != NULL)) || ((first != NULL) && (second == NULL)))
        return false;
    if (first->val != second->val)
        return false;
    if ((first->left == NULL) && (second->left == NULL))
        return judge_iso(first->right, second->right);
    if (((first->left != NULL) && (second->left != NULL)) && (first->left->val == second->left->val))
        return judge_iso(first->left, second->left) && judge_iso(first->right, second->right);
    else
        return judge_iso(first->left, second->right) && judge_iso(first->right, second->left);

}

tree* init_first_tree(tree* first)
{
    first = (tree*)malloc(sizeof(tree));
    tree* temp = first;
    temp->val = 1;
    temp->left = (tree*)malloc(sizeof(tree));
    temp = first->left;
    temp->val = 2;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 4;
    temp->right = (tree*)malloc(sizeof(tree));
    temp->right->val = 5;
    temp = temp->right;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 6;

    first->right = (tree*)malloc(sizeof(tree));
    temp = first->right;
    temp->val = 3;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 7;
    temp = temp->left;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 8;
    return first;
}

tree* init_second_tree(tree* second)
{
    tree* temp;
    second = (tree*)malloc(sizeof(tree));
    temp = second;
    temp->val = 1;
    temp->left = (tree*)malloc(sizeof(tree));
    temp = temp->left;
    temp->val = 3;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 7;
    temp = temp->left;
    temp->right = (tree*)malloc(sizeof(tree));
    temp->right->val = 8;

    second->right = (tree*)malloc(sizeof(tree));
    temp = second->right;
    temp->val = 2;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 5;
    temp = temp->left;
    temp->left = (tree*)malloc(sizeof(tree));
    temp->left->val = 6;
    temp = second->right;
    temp->right = (tree*)malloc(sizeof(tree));
    temp->right->val = 4;
    return second;
}

int main(int argc, char const *argv[])
{
    tree* first;
    tree* second;
    first = init_first_tree(first);
    second = init_second_tree(second);

    if (judge_iso(first, second))
    {
        printf("the two tree is isostructural\n");
    }
    else
    {
        printf("the two tree is not isostructural\n");
    }

    return 0;
}
