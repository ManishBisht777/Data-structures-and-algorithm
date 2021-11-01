void findpair(node *root)
{
    node *first = head;
    node *second = head;

    while (second != NULL)
    {
        second = second->next;
    }

    while (first != second && second->next != first)
    {
        if (first->data + second->data == x)
        {
            cout << first->data << " " << second->data;
            first = first->next;
            second = second->prev;
        }
        else
        {
            if (first->data + second->data < x)
            {
                first = first->next;
            }
            else
            {
                second = second->prev;
            }
        }
    }
}