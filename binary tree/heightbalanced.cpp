int isbalanced(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = isbalanced(root->left);
    if (lh == -1)
        return -1;

    int rh = isbalanaced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
    {
        return max(lh, rh) + 1;
    }
}

bool balanced(Node *root)
{
    int x = isbalanced(root);
    if (x == -1)
        return false;
    else
        return true;
}