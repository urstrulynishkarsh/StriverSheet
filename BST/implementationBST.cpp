#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

void buildBST(int val, Node *&root)
{
    if(root==NULL)
    {
        root=new Node(val);
        return;
    }
    if(root->data>val)
    {
        buildBST(val,root->left);
    }
    else{ 
        buildBST(val,root->right);
    }
}
Node *createTree()
{
    cout<<"Enter the data: ";
    int val;
    cin>>val;
    Node *root=NULL;
    while(val!=-1)
    {
        buildBST(val,root);
        cout<<"Enter the data: ";
        cin>>val;
    }
    return root;
}


void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *front=q.front();
        q.pop();
        if(front==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right) 
            {
                 q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);
}