
// method 1

Node *Reverse(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node *Delete(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    auto mx = head->data;
    auto tmp = head;
    while (tmp && tmp->next)
    {
        if (tmp->next->data < mx)
        {
            auto del = tmp->next;
            tmp->next = tmp->next->next;
            delete del;
        }
        else
        {
            mx = tmp->next->data;
            tmp = tmp->next;
        }
    }

    return head;
}

Node *compute(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    head = Reverse(head);
    head = Delete(head);
    head = Reverse(head);
    return head;
}

// method 2

Node *compute(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *temp = compute(head->next);
    if (temp->data > head->data)
        return temp;
    else
        head->next = temp;
    return head;
}