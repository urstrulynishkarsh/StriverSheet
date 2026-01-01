#include<iostream>
#include<vector>
using namespace std;

bool ispossible(vector<long long> &tree,long long int m, long long int mid)
{
    long long  int woodcollected=0;
    for(int i=0;i<tree.size();i++)
    {
        if(tree[i]>mid)
        {
            woodcollected+=tree[i]-mid;
        }
    }
    return woodcollected>=m;
}
long long int maxsawbladeheight(vector<long long> &tree,long long int m)
{
    long long int s,e,ans=-1;
    s=0;
    e=*max_element(tree.begin(),tree.end());

    while(s<=e)
    {
        long long int mid=s+(e-s)/2;
        if(ispossible(tree,m,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    long long int n,m;
    cout<<"Enter the value of n and m: ";
    cin>>n>>m;

    vector<long long> tree;
    cout<<"Enter the tree height in the array: ";
    while(n--)
    {
        long long height;
        cin>>height;
        tree.push_back(height);
    }
    cout<<maxsawbladeheight(tree,m);

}