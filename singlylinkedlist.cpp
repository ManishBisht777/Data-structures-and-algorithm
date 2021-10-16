#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertattail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool search(node *&head, int key)
{
    node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

void deleteathead(node *&head)
{
    node *todelete = head;

    head = head->next;

    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "\n\t LINKED LIST IS EMPTY";
        return;
    }
    if (head->next == NULL)
    {
        deleteathead(head);
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reverseK(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseK(nextptr, k);
    }

    return prevptr;
}

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}

bool detectcycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    if (slow == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    display(head);
    // cout << search(head, 3);

    // node *newhead = reverseK(head, 2);
    // display(newhead);

    makecycle(head, 2);
    // display(head);
    cout << detectcycle(head) << "\n";
    removecycle(head);
}