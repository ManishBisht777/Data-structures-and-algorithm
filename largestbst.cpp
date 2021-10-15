#include <iostream>
#include <climits>
#include <algorithm>
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

struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};

info largestbst(node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    info leftinfo = largestbst(root->left);
    info rightinfo = largestbst(root->right);

    info curr;
    curr.size = 1 + leftinfo.size + rightinfo.size;

    if (leftinfo.isbst && rightinfo.isbst && leftinfo.max < root->data && rightinfo.min > root->data)
    {
        curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
        curr.max = max(rightinfo.max, max(leftinfo.max, root->data));

        curr.ans = curr.size;
        curr.isbst = true;

        return curr;
    }

    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isbst = false;
    return curr;
}

int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(10);
    root->left->left = new node(2);

    cout << largestbst(root).ans;
}
