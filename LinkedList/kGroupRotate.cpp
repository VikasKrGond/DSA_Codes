#include<iostream>
using namespace std;
class LinkedList{
    public:
            int data;
            LinkedList* next;
            LinkedList(int val)
            {
                data=val;
                next=NULL;
            }
};
//K-Group Reverse Linked List
//Given a Singly linked list containing n nodes.
//The task is to reverse every group of k nodes in the list.
//If the number of nodes is not a multiple of k then left-out 
// nodes, in the end, should be considered as a group and must be reversed.
LinkedList* reverseK(LinkedList* head,int k)
{   
    // if there is single head 
    if(head==NULL || head->next==NULL) return head;
    LinkedList *dummy= new LinkedList(0);
    dummy->next = head;
    LinkedList *cur=dummy,*nex=dummy,*pre=dummy;
    int cnt=0;
    while(cur->next!=NULL) // to get the size of the Linked List
    {
        cur=cur->next;
        cnt++;
    }
    while(cnt>=k)
    {
        cur=pre->next;
        nex=cur->next;
        for(int i=1;i<k;i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex=cur->next;
        }
        pre=cur;
        cnt-=k;
    }
    return dummy->next;

}
void print(LinkedList* head)
{
    if(head==NULL) {
        cout<<"Empty Linked list\n";
        return;
    }
    cout<<"Printing the Linked List: \n";
    while(head->next!=NULL)
    {
         cout<<head->data<<" ";
         head=head->next;
    }
    cout<<endl;
}
int main()
{
    LinkedList *head = new LinkedList(1);
    head->next = new LinkedList(2);
    head->next->next = new LinkedList(3);
    head->next->next->next = new LinkedList(4);
    head->next->next->next->next = new LinkedList(5);
    print(head);
    LinkedList *newHead= reverseK(head,2);
    print(newHead);
    return 0;
}