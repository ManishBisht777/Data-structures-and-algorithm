#include <iostream>
#include <queue>

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

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *sortedtobst(int arr[], int st, int end)
{
    if (st > end)
    {
        return NULL;
    }

    int mid = (st + end) / 2;

    node *root = new node(arr[mid]);

    root->left = sortedtobst(arr, st, mid - 1);
    root->right = sortedtobst(arr, mid + 1, end);

    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *root = sortedtobst(arr, 0, 4);
    inorder(root);
}