// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457

Node *addOne(Node *head)
{
    Node *temp = head;
    Node *last = NULL;

    while (temp->next != NULL)
    {
        if (temp->data != 9)
        {
            last = temp;
        }
        temp = temp->next;
    }

    if (temp->data != 9)
    {
        temp->data++;
        return head;
    }

    if (last == NULL)
    {
        last = new Node(NULL);
        last->data = 0;
        last->next = head;
        head = last;
    }

    last->data++;
    last = last->next;
    while (last != NULL)
    {
        last->data = 0;
        last = last->next;
    }
    return head;
}