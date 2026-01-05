#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int size=n/2;
        unordered_map<int,int> hashmap;
        for(int val:nums)
        {
            hashmap[val]++;
        }
        for(auto it:hashmap)
        {
            if(it.second==size)
            {
                return it.first;
            }
        }
        return -1;
    }
int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<repeatedNTimes(nums);
    
}