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



 Node * reverse(Node *&head)
    {
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL)
        {
            Node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head=reverse(head);
        Node *temp=head;
        int carry=1;
        while(temp!=NULL)
        {
            int sum=temp->data+carry;
            int digit=sum%10;
            carry=sum/10;
            temp->data=digit;
            if(temp->next==NULL && carry!=0)
            {
                Node *newNode=new Node(carry);
                temp->next=newNode;
                temp=newNode;
            }
            temp=temp->next;
        }
        head=reverse(head);
        return head;
        // return head of list after adding one
    }



int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    // cout<<endl;
    
    Node *result=addOne(head);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
