Node *divide(int N, Node *head)
{
    Node *es = new Node(-1);
    Node *ee = es;
    Node *os = new Node(-1);
    Node *oe = os;

    while (head != NULL)
    {
        Node *temp = head->next;
        if (head->data % 2 == 0)
        {
            ee->next = head;
            ee = ee->next;
            ee->next = NULL;
        }
        else if (head->data % 2 != 0)
        {
            oe->next = head;
            oe = oe->next;
            oe->next = NULL;
        }
        head = temp;
    }
    os = os->next;
    es = es->next;
    ee->next = os;
    if (es == NULL)
        return os;
    return es;
}