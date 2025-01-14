#include<iostream>
using namespace std;
class Linked{
    public:
    int data;
    Linked *next;
    Linked(int val)
    {
        data=val;
        next =NULL;
    }
};
Linked* reverse(Linked* head)
{
    Linked *curr=head,*nex,*prev=NULL;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next = prev;
        prev =curr;
        curr=nex;
    }
    return prev;
}
void printList(Linked *head)
{
    Linked *temp = head;
    cout<<"Printing Linked List: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
     Linked *list = new Linked(5);
     list->next = new Linked(4);
     list->next->next = new Linked(3);
     list ->next->next->next = new Linked(2);
     printList(list);
     Linked *head=reverse(list);
     printList(head);
     delete(list);
}