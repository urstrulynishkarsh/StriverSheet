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

int maxLevelSum(Node *&head)
{
    int maxsum=INT_MIN;
    int resultlevel=0;
    int currentlevel=1;

    queue<Node *>q;
    q.push(head);

    while(!q.empty())
    {
        int n=q.size();
        int sum=0;

        while(n--)
        {
            Node *newnode=q.front();
            q.pop();

            sum+=newnode->data;

            if(newnode->left)
            {
                q.push(newnode->left);
            }

            if(newnode->right)
            {
                q.push(newnode->right);
            }
        }

        if(sum>maxsum)
        {
            maxsum=sum;
            resultlevel=currentlevel;
        }
        currentlevel++;

    }
    return resultlevel;
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

    cout<<maxLevelSum(root);
 
}