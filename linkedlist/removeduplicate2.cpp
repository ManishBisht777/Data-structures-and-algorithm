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

node *removeDuplicates(node *head)
{
    node *temp = head;
    while (head->next != NULL)
    {

        while (temp != NULL)
        {
            if (temp->data == head->data)
            {
                break;
            }
            else
            {
                temp->next = head;
            }
        }
        head = head->next;
    }
    return temp;
}

int main()
{
    node *head = NULL;
    insertattail(head, 3);
    insertattail(head, 5);
    insertattail(head, 5);
    insertattail(head, 3);
    insertattail(head, 2);
    display(head);
    node *newhead = removeDuplicates(head);
    display(newhead);
}