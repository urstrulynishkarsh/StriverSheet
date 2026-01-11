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

int getLength(Node* head) {
        // Your code goes here
        int len=0;
        Node* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }

Node* removeNthFromEnd(Node* head, int n) {
    int len=getLength(head);
    int pos=len-n+1;
    int i=1;
    Node *prev=head;
    while(i<pos-1)
    {
        prev=prev->next;
        i++;
    }
    prev->next=prev->next->next;
    return head;
}
int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    cout<<endl;
    int n;
    cout<<"Enter the nth node delete from last: ";
    cin>>n;

    Node *result=removeNthFromEnd(head,n);

    printLinkedList(result);
    
    
}
