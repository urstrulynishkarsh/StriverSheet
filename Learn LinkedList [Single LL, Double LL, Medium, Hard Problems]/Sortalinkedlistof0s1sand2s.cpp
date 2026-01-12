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


Node *sort012(Node *&head)
{
    Node *zeroNode=new Node(0);
    Node *temp1=zeroNode;

    Node *oneNode=new Node(0);
    Node *temp2=oneNode;

    Node *twoNode=new Node(0);
    Node *temp3=twoNode;

    Node *temp=head;
    while(temp)
    {
        if(temp->data==0)
        {
            temp1->next=temp;
            temp1=temp;
        }
        else if(temp->data==1)
        {
            temp2->next=temp;
            temp2=temp;
        }
        else if(temp->data==2){
            temp3->next=temp;
            temp3=temp;
        }
        temp=temp->next;
    }

    temp1->next=(oneNode->next)?oneNode->next:twoNode->next;
    temp2->next=twoNode->next;
    temp3->next=NULL;


    Node *result=zeroNode->next;

    delete zeroNode;
    delete oneNode;
    delete twoNode;
    return result;
}

int main()
{
    Node* head = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(head);
    cout<<endl;
    
    Node *result=sort012(head);
    printLinkedList(result);
    cout<<endl;
}
