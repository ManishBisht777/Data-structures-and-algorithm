void inorder(node *root)
{
    stack<node *> s;

    node *curr = root;

    while (!s.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr->data;
            curr = curr->right;
        }
    }
}