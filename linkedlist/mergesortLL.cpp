Node *findmid(Node *head)
{

    if (head == NULL or head->next == NULL)
        return head;

    Node *fastptr = head;
    Node *slowptr = head;

    while (fastptr and fastptr->next)
    {
        fastptr = fastptr->next->next;
        if (fastptr)
            slowptr = slowptr->next;
    }

    return slowptr;
}
// merge Function.....
Node *merge(Node *head1, Node *head2)
{

    if (!head1 and head2)
        return head2;
    if (head1 and !head2)
        return head1;

    if (!head1 and !head2)
        return head1;

    Node *reshead = NULL;
    Node *curr = NULL;

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 and ptr2)
    {

        if (ptr1->data <= ptr2->data)
        {
            if (!reshead)
            {
                reshead = ptr1;
                curr = ptr1;
            }

            else
            {
                curr->next = ptr1;
                curr = curr->next;
            }

            ptr1 = ptr1->next;
        }

        else
        {

            if (!reshead)
            {
                reshead = ptr2;
                curr = ptr2;
            }

            else
            {
                curr->next = ptr2;
                curr = curr->next;
            }

            ptr2 = ptr2->next;
        }
    }

    while (ptr1)
    {
        curr->next = ptr1;
        curr = curr->next;
        ptr1 = ptr1->next;
    }

    while (ptr2)
    {
        curr->next = ptr2;
        curr = curr->next;
        ptr2 = ptr2->next;
    }

    if (!ptr1 and !ptr2)
        curr->next = NULL;

    return reshead;
}

Node *mergeSort(Node *head)
{
    // your code here
    if (head and !head->next)
        return head; // LL having only one node.....

    if (head and head->next)
    {
        Node *mid = findmid(head);
        Node *head1 = (mid != NULL) ? (mid->next) : NULL;
        mid->next = NULL;
        head = mergeSort(head);
        head1 = mergeSort(head1);
        return merge(head, head1);
    }
}