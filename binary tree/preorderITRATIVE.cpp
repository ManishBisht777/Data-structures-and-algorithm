void preorder(node *root)
{
    stack<node *> s;

    node *curr = root;

    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        cout << curr->data;

        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
}