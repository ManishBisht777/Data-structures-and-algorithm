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

void printlevel(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int calcheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(calcheight(root->left), calcheight(root->right)) + 1;
}

int calcdia(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = calcheight(root->left);
    int rh = calcheight(root->right);

    int currdia = lh + rh + 1;
    int ldia = calcdia(root->left);
    int rdia = calcdia(root->right);

    return max(currdia, max(ldia, rdia));
}

int calccdia2(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldia = calccdia2(root->left, &lh);
    int rdia = calccdia2(root->right, &rh);

    int currdia = lh + rh + 1;

    *height = max(lh, rh) + 1;

    return max(currdia, max(ldia, rdia));
}

void sumreplace(node *root)
{
    if (root == NULL)
    {
        return;
    }

    sumreplace(root->left);
    sumreplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (isbalanced(root->left) == false)
    {
        return false;
    }

    if (isbalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isbalanced2(node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;

    if (!isbalanced2(root->left, &lh))
    {
        return false;
    }
    if (!isbalanced2(root->right, &rh))
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void rightview(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
void leftview(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return lca(root->left, n1, n2);
    }

    return lca(root->right, n1, n2);
}

int finddist(node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dist;
    }

    int left = finddist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }

    return finddist(root->right, k, dist + 1);
}

int distbwtnodes(node *root, int n1, int n2)
{
    node *lc = lca(root, n1, n2);

    int d1 = finddist(lc, n1, 0);
    int d2 = finddist(lc, n2, 0);

    return d1 + d2;
}

void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;

        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

void printsubtreenodes(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printsubtreenodes(root->left, k - 1);
    printsubtreenodes(root->right, k - 1);
}

int printnodesatk(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printsubtreenodes(root, k);
        return 0;
    }

    int dl = printnodesatk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreenodes(root->right, k - dl - 2);
        }

        return dl + 1;
    }

    int dr = printnodesatk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreenodes(root->left, k - dr - 2);
        }

        return dr + 1;
    }

    return -1;
}

bool getpath(node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getpath(root->left, key, path) || getpath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
    {
        return -1;
    }

    int pc;

    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc - 1];
}

node *LCA2(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *leftlca = LCA2(root->left, n1, n2);
    node *rightlca = LCA2(root->right, n1, n2);

    if (leftlca && rightlca)
    {
        return root;
    }

    if (leftlca != NULL)
    {
        return leftlca;
    }
    return rightlca;
}
int main()
{
    node *root = new node(1);
    root->right = new node(3);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // root->right->left->left = new node(68);
    // root->right->left->left->left = new node(69);

    // preorder(root);
    // cout << "\n";
    // inorder(root);
    // cout << "\n";
    // postorder(root);

    // int inorder[] = {4, 2, 1, 5, 3};
    // // int preorder[] = {1, 2, 4, 3, 5};
    // int postorder[] = {4, 2, 5, 3, 1};

    // node *root = buildT(postorder, inorder, 0, 4);
    // display(root);

    // printlevel(root);

    // int height = 0;
    // cout << calccdia2(root, &height);

    // preorder(root);
    // cout << "\n";
    // sumreplace(root);
    // preorder(root);

    // int height = 0;
    // if (isbalanced2(root, &height) == true)
    // {
    //     cout << "true";
    // }
    // else
    // {
    //     cout << "false";
    // }
    // return 0;

    // rightview(root);
    // cout << "\n";
    // leftview(root);

    // cout << distbwtnodes(root, 4, 5);

    // flatten(root);
    // inorder(root);

    // printnodesatk(root, root, 2);

    node *pc = LCA2(root, 7, 6);
    cout << pc->data;
}
