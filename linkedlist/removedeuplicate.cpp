void removeDuplicates(node *head)
{
    while (head->next != NULL)
    {
        if (head == NULL || head->next == NULL)
            return head;

        if (head->data == head->next->data)
        {
            head->next = head->next->next;
        }
        else
        {
            head = head->next;
        }
    }
}