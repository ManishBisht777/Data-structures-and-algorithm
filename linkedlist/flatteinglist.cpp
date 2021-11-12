Node *flat(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    Node *list1 = root, *list2 = root->next, *dummy = new Node(0);
    Node *saved = list2->next;

    while (list2)
    {
        Node *temp = dummy;
        while (list1 && list2)
        {
            if (list1->data <= list2->data)
            {
                temp->bottom = list1;
                list1 = list1->bottom;
            }
            else
            {
                temp->bottom = list2;
                list2 = list2->bottom;
            }
            temp = temp->bottom;
        }

        if (list1)
        {
            temp->bottom = list1;
            list1 = list1->bottom;
        }
        else if (list2)
        {
            temp->bottom = list2;
            list2 = list2->bottom;
        }

        list1 = dummy->bottom;
        list2 = saved;
        if (saved)
            saved = list2->next;
    }

    return dummy->bottom;
}