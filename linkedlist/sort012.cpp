# include <iostream>

using namespace std;

Node* sort012(Node* root)
{
    if(root->next==NULL)
    {
        return root;
    }

    Node* oned=new Node(0);
    Node* twod=new Node(1);
    Node* zerod=new Node(2);

    Node* zero=zerod;
    Node* two=twod;
    Node* one=oned;

    Node* curr=head;
    while(curr)
    {
        if(curr->data==0)
        {
            zero->next=curr;
            curr=curr->next;
            zero=zero->next;
        }
        else if(curr->data==1)
        {
            one->next=curr;
            curr=curr->next;
            one=one->next;
        }
        else{
                two->next=curr;
                curr=curr->next;
                two=two->next;
        }
    }

    zero->next=(oned->next)?(oned->next):twod->next;
    one->next=twod->next;
    two->next=NULL;

    root=oned->next;

    delete oned;
    delete twod;
    delete zerod;

    return root;
}