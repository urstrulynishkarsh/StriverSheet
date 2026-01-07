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
 Node *reverseLL(Node* &head, Node *curr, Node *prev) {
        // Your code goes here
    if(curr==NULL)
    {
        return prev;
    }

    Node *temp=curr->next;
    curr->next=prev;
    return reverseLL(head,temp,curr);
}


int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    // cout<<endl;

    Node *curr=head;
    Node *prev=NULL;
    
    Node *result=reverseLL(head,curr,prev);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
