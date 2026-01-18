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

  Node* mergeNodes(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        Node *slow=head;
        Node *fast=head->next;
        Node *lastNode=0;
        int sum=0;
        while(fast!=NULL)
        {
            if(fast->data!=0)
            {
                sum+=fast->data;
            }
            else{
                slow->data=sum;
                lastNode=slow;
                slow=slow->next;
                sum=0;
            }
            fast=fast->next;
        }
        lastNode->next=NULL;
       
        return head;

    }


int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    // cout<<endl;
    
    Node *result=mergeNodes(head);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
