#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


vector<int> twosum(vector<int>& nums, int target) {
       unordered_map<int,int> hashmap;
       for(int i=0;i<nums.size();i++)
       {
            int complement=target-nums[i];
            if(hashmap.count(complement))
            {
                return {hashmap[complement],i};
            }
            hashmap[nums[i]]=i;
       }
       return {-1,-1};
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
    

    vector<int> result=twosum(arr,k);
    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}