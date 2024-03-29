void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if (head->next == NULL)
        return;
    Node *fast = head;
    Node *slow = head;
    *head1_ref = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    *head1_ref = head;

    if (head1_ref->next != head)
    {
        *head2_ref = slow->next;
    }

    fast->next = slow->next;
    slow->next = head;
}