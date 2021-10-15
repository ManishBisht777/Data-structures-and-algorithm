#include <iostream>
#include <queue>
#include <stack>

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

bool isbbst(node *root, node *min = NULL, node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }

    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool left = isbbst(root->left, min, root);
    bool right = isbbst(root->right, root, max);
    return left && right;
}

void zigzag(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> currlvl;
    stack<node *> nxtlvl;

    bool lefttoright = true;

    currlvl.push(root);

    while (!currlvl.empty())
    {
        node *temp = currlvl.top();
        currlvl.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (lefttoright)
            {
                if (temp->left)
                {
                    nxtlvl.push(temp->left);
                }
                if (temp->right)
                {
                    nxtlvl.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nxtlvl.push(temp->right);
                }
                if (temp->left)
                {
                    nxtlvl.push(temp->left);
                }
            }
        }

        if (currlvl.empty())
        {
            lefttoright = !lefttoright;
            swap(currlvl, nxtlvl);
        }
    }
}

bool isidentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isidentical(root1->left, root2->left);
        bool cond3 = isidentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    node *root = NULL;
    root = insertbst(root, 12);
    insertbst(root, 9);
    insertbst(root, 15);
    insertbst(root, 5);
    insertbst(root, 10);

    node *root1 = NULL;
    root = insertbst(root1, 12);
    insertbst(root1, 9);
    insertbst(root1, 15);
    insertbst(root1, 5);
    insertbst(root1, 1);

    // inorder(root);

    // if (searchinbst(root, 10) == NULL)
    // {
    //     cout << "not found";
    // }
    // else
    // {
    //     cout << "found";
    // }

    // cout << "\n";
    // deleteinbst(root, 5);
    // inorder(root);

    // if (isbbst(root, NULL, NULL))
    // {
    //     cout << "valid";
    // }
    // else
    // {
    //     cout << "invalid";
    // }

    // zigzag(root);

    if (isidentical(root, root1))
    {
        cout << "\n\t identical";
    }
    else
    {
        cout << "not";
    }
}