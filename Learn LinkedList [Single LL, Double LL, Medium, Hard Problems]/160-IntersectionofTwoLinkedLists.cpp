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
        int len=0;
        Node *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    Node *getIntersectionNode(Node *headA, Node *headB) {
        int len1=length(headA);
        int len2=length(headB);
        int count;
        if(len1<len2)
        {
            count=len2-len1;
            while(count--)
            {
                headB=headB->next;
            }
        }
        else{
            count=len1-len2;
            while(count--)
            {
                headA=headA->next;
            }
        }
        while(headA && headB)
        {
            if(headA==headB)
            {
                return headA;
            }
             headA=headA->next;
             headB=headB->next;
        }
        return NULL;

    }


int main()
{
    Node* headA = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(headA);
    // cout<<endl;

    Node* headB = createLinkedList();
    cout << "\nLinked List: ";
    printLinkedList(headB);
    
    Node *result=getIntersectionNode(headA,headB);

    
    printLinkedList(result);

    
}
