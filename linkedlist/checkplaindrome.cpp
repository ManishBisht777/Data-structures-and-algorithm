bool isPalindrome(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) //finding Middle of linked list
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = NULL;
    Node *curr = slow;
    while (curr != NULL) // reversing list from middle
    {
        Node *t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    fast = head;
    while (prev != NULL) //checking for palindrome
    {
        if (fast->data != prev->data)
            return false;
        prev = prev->next;
        fast = fast->next;
    }
    return true;
}