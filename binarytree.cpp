#include <iostream>

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
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildtree(int preorder[], int inorder[], int st, int end)
{
    if (st > end)
    {
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;

    node *n = new node(curr);

    int pos = search(inorder, st, end, curr);
    if (st == end)
    {
        return n;
    }

    n->left = buildtree(preorder, inorder, st, pos - 1);
    n->right = buildtree(preorder, inorder, pos + 1, end);

    return n;
}

node *buildT(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;

    if (start > end)
    {
        return NULL;
    }

    int val = postorder[idx];
    idx--;

    node *n = new node(val);

    if (start == end)
    {
        return n;
    }

    int pos = search(inorder, start, end, val);

    n->right = buildT(postorder, inorder, pos + 1, end);
    n->left = buildT(postorder, inorder, start, pos - 1);

    return n;
}

void display(node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
int main()
{
    // struct node *root = new node(1);
    // root->right = new node(3);
    // root->left = new node(2);

    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    // preorder(root);
    // cout << "\n";
    // inorder(root);
    // cout << "\n";
    // postorder(root);

    int inorder[] = {4, 2, 1, 5, 3};
    // int preorder[] = {1, 2, 4, 3, 5};
    int postorder[] = {4, 2, 5, 3, 1};

    node *root = buildT(postorder, inorder, 0, 4);
    display(root);
}
