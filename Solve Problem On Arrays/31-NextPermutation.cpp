#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

void nextpermutation(vector<int>& nums) {
    int i=nums.size()-1;
    while(i>0 && nums[i-1]>=nums[i])
    {
        i--;
    }
    if(i==0)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    int j=nums.size()-1;
    while(j>0 && nums[i-1]>=nums[j])
    {
        j--;
    }
    swap(nums[i-1],nums[j]);
    reverse(nums.begin()+i,nums.end());
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

    nextpermutation(arr);
    for(int val:arr)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}