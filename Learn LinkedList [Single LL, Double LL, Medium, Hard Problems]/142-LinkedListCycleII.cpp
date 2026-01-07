#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data=x;
        next=NULL;
    }
};

void printLinkedList(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " -> ";
        temp=temp->next;
    }
    cout<<"NULL";
}




Node *detectCycle(Node *&head) {
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
            if(slow==fast)
            {
                 slow=head;
                break;
            }
        }
        if(fast==NULL || fast->next==NULL)
        {
            return NULL;
        }
       
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
int main()
{
   Node *first=new Node(10);
   Node *second=new Node(20);
   Node *thrid=new Node(30);
   Node *fourth=new Node(40);
   Node *fifth=new Node(50);
   first->next=second;
   second->next=thrid;
   thrid->next=fourth;
   fourth->next=fifth;
   fifth->next=second;

   Node *result=detectCycle(first);

   if(result != NULL)
{
    cout << "Cycle detected at node with value: " << result->data << endl;
}
else
{
    cout << "No cycle detected" << endl;
}

    
}
