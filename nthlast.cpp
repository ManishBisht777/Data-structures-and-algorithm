int nthlast(Node *head, int n)
{
    Node *curr = head;
    int count = 0;
    Node *current = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    if (count < n)
        return -1;

    int k = c - n;
    while (k--)
    {
        current = current->next;
    }
    return current->data;
}
