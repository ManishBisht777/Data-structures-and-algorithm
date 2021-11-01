void rotate(node *&head, int pos)
{
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;
    int count = 1;
    while (count < = pos)
    {
        temp = temp->next;
        head = head->next;
        count++;
    }

    temp->next = NULL;
    head->prev = NULL;
}