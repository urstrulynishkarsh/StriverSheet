#include<iostream>
#include<vector>
using namespace std;

vector<int> findClosestElements(vector<int> &nums, int k, int x)
{
    vector<int> result;
    priority_queue<pair<int, int> >pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push({abs(nums[i]-x),nums[i]});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }
    sort(result.begin(),result.end());
    return result;
}

int main()
{
     int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    int x;
    cout<<"Enter the value of x: ";
    cin>>x;

    vector<int> ans=findClosestElements(arr,k,x);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
}