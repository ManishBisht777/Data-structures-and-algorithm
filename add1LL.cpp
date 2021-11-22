Node *addone(Node *head)
{
    int carry = 1;
    check(head, carry);
    if (head->data == 0)
    {
        Node *h = new Node(1);
        h->next = head;
        return h;
    }

    return head;
}

void check(Node *head, int &carry)
{
    if (head->next)
        check(head->next, carry);

    if (carry == 1)
    {
        if (head->data == 9)
        {
            head->data = 0;
        }
        else
        {
            head->data += 1;
            carry = 0;
        }
    }
}