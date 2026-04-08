#include<iostream>
#include<vector>
using namespace std;

int Kthlargestelement(vector<int> &nums,int k)
{
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push(nums[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
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

    cout<<Kthlargestelement(arr,k);
}