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

int nodelength(node *head)
{
    node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

node *appendk(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;

    int l = nodelength(head);
    k = k % l;
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        count++;
        tail = tail->next;
    }

    newtail->next = NULL;
    tail->next = head;
    return newhead;
}

int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);
    insertattail(head, 7);
    insertattail(head, 8);
    display(head);

    node *newhead = appendk(head, 3);
    display(newhead);

    return 0;
}