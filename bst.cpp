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

node *insertbst(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (val < root->data)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }

    return root;
}

node *searchinbst(node *root, int key)
{
    if (root == NULL)
    {

        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchinbst(root->left, key);
    }

    return searchinbst(root->right, key);
}

node *inordersucc(node *root)
{
    node *curr = root;

    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

node *deleteinbst(node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right, temp->data);
    }

    return root;
}

int main()
{
    node *root = NULL;
    root = insertbst(root, 5);
    insertbst(root, 1);
    insertbst(root, 3);
    insertbst(root, 4);
    insertbst(root, 2);
    insertbst(root, 7);

    inorder(root);

    // if (searchinbst(root, 10) == NULL)
    // {
    //     cout << "not found";
    // }
    // else
    // {
    //     cout << "found";
    // }

    cout << "\n";
    deleteinbst(root, 5);
    inorder(root);
}