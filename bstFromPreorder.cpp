#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *constructbst(int preorder[], int *preorderidx, int key, int min, int max, int n)
{
    if (*preorderidx >= n)
    {
        return NULL;
    }

    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preorderidx += 1;

        if (*preorderidx < n)
        {
            root->left = constructbst(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        }
        if (*preorderidx < n)
        {
            root->right = constructbst(preorder, preorderidx, preorder[*preorderidx], key, max, n);
        }
    }
    return root;
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int preorder1[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderidx = 0;
    node *root = constructbst(preorder1, &preorderidx, preorder1[0], INT_MIN, INT_MAX, n);
    preorder(root);
}