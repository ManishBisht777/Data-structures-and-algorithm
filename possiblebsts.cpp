#include <iostream>
#include <vector>
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

vector<node *> construct(int st, int end)
{
    vector<node *> trees;

    if (st > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = st; i <= end; i++)
    {
        vector<node *> leftsubtree = construct(st, i - 1);
        vector<node *> rightsubtree = construct(i + 1, end);

        for (int j = 0; j < leftsubtree.size(); j++)
        {
            node *left = leftsubtree[j];
            for (int k = 0; k < rightsubtree.size(); k++)
            {
                node *right = rightsubtree[k];

                node *n = new node(i);
                n->left = left;
                n->right = right;
                trees.push_back(n);
            }
        }
    }

    return trees;
}

int main()
{
    vector<node *> total;
    total = construct(1, 3);

    for (int i = 0; i < total.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(total[i]);
        cout << "\n";
    }
}