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




Node *createLinkedList()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) 
    {
        return NULL;
    }

    int val;
    cout << "Enter data for node 1: ";
    cin >> val;

    Node* head = new Node(val);
    Node* temp = head;

    for (int i = 2; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }

    return head;
}

int length(Node *head)
{
    Node *temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
   
}

Node *rotate(Node *head, int k)
{
    
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    int len=length(head);
    int acutalLength=k%len;
    if(acutalLength==0)
    {
        return head;
    }
    int LastNodePosition=len-acutalLength-1;
    Node *prev=head;
    int i=0;
    while(i<LastNodePosition)
    {
        i++;
        prev=prev->next;

    }
    Node *curr=prev->next;
    prev->next=NULL;

    Node *newhead=curr;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=head;
    return newhead;

}





int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    cout<<endl;

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Node *result=rotate(head,k);
    printLinkedList(result);

    
}
