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


Node* removeElements(Node* head, int val) {
        Node *result=new Node(-1);
        result->next=head;
        Node *temp=result;
        while(head!=NULL)
        {
            if(head->data!=val)
            {
                temp->next=head;
                temp=head;
            }
            head=head->next;
        }
        temp->next=NULL;
        return result->next;
    }





int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    // cout<<endl;

    int val;
    cout<<"Enter the val: ";
    cin>>val;
    
    Node *result=removeElements(head,val);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
