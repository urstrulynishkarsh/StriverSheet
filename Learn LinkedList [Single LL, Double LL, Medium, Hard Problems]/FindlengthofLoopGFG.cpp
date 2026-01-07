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




int lengthOfLoop(Node *head) {
        // code here
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==fast)
            {
                 int len=1;
                 fast=fast->next;
                 while(slow!=fast)
                 {
                    fast=fast->next;
                    len++;
                 }
                 return len;
            }
        }
    return 0;
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

   cout<<lengthOfLoop(first);



    
}
