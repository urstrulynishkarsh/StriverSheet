#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int minCost(vector<int>& nums) {
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push(nums[i]);
    }
    int cost=0;
    while(pq.size()>1)
    {
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int mergelength=first+second;
        pq.push(mergelength);
        cost+=mergelength;
    }
    return cost;
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

    

    cout<<minCost(arr);

    return 0;
    
   
}