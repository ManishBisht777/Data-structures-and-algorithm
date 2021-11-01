node *reverseDLL(node *head)
{
    node *curr = head;
    node *newhead = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (curr != NULL)
    {
        newhead = curr->prev;
        curr->prev = curr->next;
        curr->next = newhead;
        curr = curr->prev;
    }

    return curr->prev;
}