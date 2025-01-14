#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class List
{
public:
    int data;
    List *next;
    List(int val)
    {
        this->data = val;
        next = NULL;
    }
};
//Reversing the Linked List
List * revList(List* head)
{
    List* newHead= NULL;
    while(head!=NULL)
    {
        List* next=head->next;
        head->next=newHead;
        newHead=head;
        head=next;
    }
    return newHead;
}
//Delete Node 
/*
   Approach copy the value if next node and 
   break the Link and Link it to next to next
*/
void delNode(List* node)
{
    node->data = node->next->data;
    node->next = node->next->next;
    delete node;
}
List* delNthFromEnd(List* Node,int n)
{
    /*
       We use two pointers fast and slow first we move the 
       fast pointer till n then we start moving both pointer
       simultanesously till fast reaches null then delete the node 
       pointed by the slow pointer 
    */
   List* start=new List(0);
   start->next = Node;
   List* slow=Node,*fast=Node;
   while(n--)
   {
       fast=fast->next;
   }
   while(fast)
   {
      fast=fast->next;
      slow=slow->next;
   }
   slow->next =slow->next->next;
   return start->next;
  
}
//Printing the List 
void printList(List *head)
{
    List *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

//Middle of a Linked List
/*
    We'll have two pointers slow and fast, we'll move fast 2 step at a time
    and also we move slow one step at a time till fast reaches null
    or out of bound then we'll return the slow pointer
*/
List* middleLL(List* head)
{
    List* slow=head;
    List* fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow =slow->next;
    }
    return slow;
}
/*
    Approach is We'll do simple thing just add the node of
    both list parallely then if sum is greater than 9 then 
    insert value in the carry and also create a separate List
    to store the sum value. We define sum inside the loop and 
    iterate through the end or both list and cary > 0 
    first we check whether l1 is not empty then the value of node is sum
    then same for the l2 then we computer the carry as sum/10
    then we create a new node in which we'll store the sum remainder value 
    i.e sum%10 then we move the pointer and again iterate
    T.C of the solution O(max(l1,l2))+1(for carry)
    S.C O(max(l1,l2))+1 ( for carry)
*/
List* addTwoLL(List* l1,List* l2)
{
    List* dummy=new List(0);
    List* temp = dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        List* node = new List(sum%10); // Creating New List to 
        // Store the ans 
        temp->next = node;
        temp=temp->next;
    }
    return dummy->next;
}
//Intersection of Two List
/*
    We'll use the two poiner approach one pointer pointes to 
    the head of l1 and other one pointes to the head of l2 we'll
    move both till either they reaches at end or either they collide
    if they reach the end before colliding we'll reverse the 
    pointer with the alternative head 
*/
List* intersection(List* l1,List* l2)
{
    if(l1==NULL || l2==NULL) return NULL;
    List* headA=l1;
    List* headB=l2;
    while(headA!=headB)
    {
        headA=headA==NULL?headB: headA->next; 
        headB=headB==NULL?headA: headB->next; 
    }
    return headA;
}
/* Our Approach is simple we'll break the list in groups of size k
   keeping track of the prevlast then we'll reverse the 
   list then we'll re-link it 
   so we need two helping function like getKthNode(temp,k)
   also reverseList(head)
*/
List* reverseList(List* head)
{
     List* temp=head;
     List* prev=NULL;
     while(temp!=NULL)
     {
        List* front= temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
     }
     return prev;
}
List* getKthNode(List* head,int k)
{
  k-=1;
  while(head!=NULL)
  {
    head=head->next;
  }
  return head;
}
List* reverseKGroup(List* head,int k)
{
    List* temp=head;
    List* prevLast=NULL;
    while(temp!=NULL)
    {
        List* kthNode=getKthNode(temp,k);
        if(kthNode==NULL)
        {
            if(prevLast){
                prevLast->next=temp;
                break;
            }
        }
        List* nextNode=kthNode->next;
        kthNode->next=NULL;
        reverseList(temp);
        if(temp==head)
        {
            head=kthNode;
        }
        else{
            prevLast->next=kthNode;
        }
        prevLast=temp;
        temp=nextNode;
    }
    return head;

}
//Sandeep Code K Group Rev
List* reverseKGroup1(List* head,int k)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    int cnt = 1;
    List* temp = head;
    while(temp->next != NULL and cnt <= k){
        cnt+=1;
        temp = temp->next;
    }
    if(cnt<k){
        return head;
    }
    int i = 1;
    List* cur = head;
    List* prev = NULL;
    List* nxt = NULL;
    while(cur!=NULL and i<=k){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        i+=1;
    } 
    if(nxt){
        head->next = reverseKGroup1(nxt,k);
    }
return prev;
}
int main()
{
    List * head=new List(2);
    head->next = new List(3);
    head->next->next = new List(4);
    head->next->next->next = new List(1);
    printList(head);

    // List* newHead=revList(head);
    // List * newH=newHead->next->next;
    // printList(head);
    // delNode(newHead->next);
    // printList(newHead);
    // List *l1= new List(4);
    // List *l2= new List(8);
    // l1->next = new List(8);
    // l2->next = new List(9);
    // l1->next->next = new List(3);
    // l2->next->next = new List(7);
    // printList(l1);
    // printList(l2);
    // printList(addTwoLL(l1,l2));
    // cout<<intersection(l1,l2)->data<<"endl";
    // cout<<middleLL(head)->data;
    printList(reverseKGroup(head,2));
    return 0;
}