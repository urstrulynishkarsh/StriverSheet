#include<iostream>
#include <queue>
#include<vector>
using namespace std;
long long  MOD=1e9+7;


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

long long dfs(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    root->data+=dfs(root->left)+dfs(root->right);
    return root->data;
}
int maxProduct(Node *root)
{
    long long total=dfs(root);
    long long  ans=0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        int data=node->data;
        long long curr=(total-data)*data;
        ans=max(ans,curr);

        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    return ans%MOD;
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

    cout<<maxProduct(root);
 
}