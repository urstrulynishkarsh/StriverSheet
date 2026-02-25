#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
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

// for priority queue
class cmp{
    public:
    bool operator()(Node *a, Node *b)
    {
        return a->data>b->data;
    }
};

void traverse(Node *root, vector<string> &ans, string temp)
{
    if(root->left==NULL && root->left==NULL)
    {
        ans.push_back(temp);
        return;
    }
    traverse(root->left,ans,temp+'0');
    traverse(root->right,ans,temp+'1');
    
}
vector<string> huffmanCodes(string &str, vector<int> &f,int &n)
{
    priority_queue<Node *,vector<Node *>,cmp > pq;
    for(int i=0;i<n;i++)
    {
        Node *temp=new Node(f[i]);
        pq.push(temp);
    }

    while(pq.size()>1)
    {
        Node *left=pq.top();
        pq.pop();
        Node *right=pq.top();
        pq.pop();

        Node *newNode=new Node(left->data+right->data);
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }
    Node *root=pq.top();
    vector<string> ans;
    string temp;
    traverse(root,ans,temp);
    return ans;
}

int main()
{
  
    string str;
    cout<<"Enter the string: ";
    cin>>str;
      int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> f(n);
    cout<<"Enter the element in the f: ";
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }

    

    vector<string> result=huffmanCodes(str,f,n);

    for(auto val:result)
    {
        cout<<val<<" ";
    }
    return 0;
    
   
}