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



Node *AddtwoNumber(Node *l1,Node *l2)
{
    Node *result=new Node(-1);
    Node *temp=result;
    int carry=0;
    while(l1||l2||carry)
    {
        int a=l1?l1->data:0;
        int b=l2?l2->data:0;
        int sum=a+b+carry;
        int digit=sum%10;
        carry=sum/10;
        temp->next=new Node(digit);
        temp=temp->next;
        l1=l1?l1->next:NULL;
        l2=l2?l2->next:NULL;
    }
    return result->next;
}



int main()
{
    Node* list1 = createLinkedList();
    cout << "\nLinked List first: ";
    printLinkedList(list1);
    cout<<endl;
    

    Node* list2 = createLinkedList();
    cout << "\nLinked List second: ";
    printLinkedList(list2);
    cout<<endl;

    Node *result=AddtwoNumber(list1,list2);

     cout << "\n reverse Linked List: ";
    printLinkedList(result);

    
}
