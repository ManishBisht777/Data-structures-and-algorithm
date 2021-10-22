void postorder(node *root)
{
    stack<node *> s;
    stack<node *> out;

    s.push(root);

    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        out.push(curr);

        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out->data;
        out.pop();
    }
}