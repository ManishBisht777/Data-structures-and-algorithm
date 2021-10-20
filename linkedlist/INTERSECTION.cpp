int lengthL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int l1 = lengthL(head1);
    int l2 = lengthL(head2);

    Node *p1;
    Node *p2;
    int d;

    if (l1 > l2)
    {
        d = l1 - l2;
        p1 = head1;
        p2 = head2;
    }
    else
    {
        d = l2 - l1;
        p1 = head2;
        p2 = head1;
    }
    while (d--)
    {
        p1 = p1->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
        {
            return p1->data;
        }

        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}