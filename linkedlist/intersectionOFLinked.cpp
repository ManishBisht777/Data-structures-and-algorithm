Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    Node *newhead = NULL;
    Node *prev = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            Node *temp = new Node(head1->data);
            if (newhead == NULL)
            {
                newhead = temp;
                prev = newhead;
            }
            else
            {
                prev->next = temp;
                prev = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
    }
    return newhead;
}