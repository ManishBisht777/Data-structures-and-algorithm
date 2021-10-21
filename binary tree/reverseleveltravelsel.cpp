vector<int> reverseLevelOrder(Node *root)
{
    stack<Node *> S;
    queue<Node *> Q;
    vector<int> v;
    Q.push(root);

    while (Q.empty() == false)
    {
        root = Q.front();
        Q.pop();
        S.push(root);

        if (root->right)
            Q.push(root->right);

        if (root->left)
            Q.push(root->left);
    }

    while (S.empty() == false)
    {
        root = S.top();
        v.push_back(root->data);
        S.pop();
    }
    return v;
}