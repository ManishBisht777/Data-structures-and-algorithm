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

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void inserttail(node *&head, int val)
{

    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void deletehead(node *&head)
{
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}
void deltetion(node *&head, int pos)
{
    if (pos == 1)
    {
        deletehead(head);
        return;
    }
    node *temp = head;

    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL \n";
}

int main()
{
    node *head = NULL;

    inserttail(head, 1);
    inserttail(head, 2);
    inserttail(head, 3);
    inserttail(head, 4);
    inserttail(head, 5);

    display(head);
    deltetion(head, 3);
    deletehead(head);
    display(head);
    return 0;
}