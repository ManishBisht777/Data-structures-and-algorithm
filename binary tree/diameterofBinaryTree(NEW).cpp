int calcheight(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = calcheight(root->left, ans);
    int rh = calcheight(root->right, ans);

    ans = max(ans, 1 + hl + rh);

    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    // code here
    if (root == NULL)
    {
        return 0;
    }
    int ans = INT_MIN;
    calcheight(root, ans);
    return ans;
}