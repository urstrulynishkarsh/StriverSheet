#include<iostream>
#include<vector>
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

Node *insert(Node *&root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

Node *BuildBST(vector<int> &nums)
{
    Node *root=NULL;
    for(int val:nums)
    {
        root=insert(root,val);
    }
    return root;
}

void inorder(Node *&root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

  int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    Node* subtreeWithAllDeepest(Node* root) {
        int l=height(root->left);
        int r=height(root->right);
        if(l==r)
        {
            return root;
        }
        Node *node;
        if(l>r)
        {
            node=subtreeWithAllDeepest(root->left);
        }
        else{
            node=subtreeWithAllDeepest(root->right);
        }
        return node;
    }
int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;

    vector<int> array(n);
    cout<<"Enter the element in the Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    Node *root=BuildBST(array);

    Node *result=subtreeWithAllDeepest(root);

    inorder(result);
 
}