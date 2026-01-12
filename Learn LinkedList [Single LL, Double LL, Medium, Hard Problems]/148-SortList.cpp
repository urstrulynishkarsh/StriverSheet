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


Node *TortoiseAlgo(Node *&head)
{
    Node *slow=head;
    Node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


Node * mergeLL(Node *&left, Node *&right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    Node *ans=new Node(-1);
    Node *temp=ans;
    while(left && right)
    {
        if(left->data<right->data)
        {
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    while(left)
    {
        temp->next=left;
        left=left->next;
        temp=temp->next;
    }
    while(right)
    {
        temp->next=right;
        right=right->next;
        temp=temp->next;
    }
    return ans->next;
}

Node *sortList(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *mid=TortoiseAlgo(head);
    Node *left=head;
    Node *right=mid->next;
    mid->next=0;

    left=sortList(left);
    right=sortList(right);

    Node *merge=mergeLL(left,right);
    return merge;



}


int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    // cout<<endl;
    
    Node *result=sortList(head);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
