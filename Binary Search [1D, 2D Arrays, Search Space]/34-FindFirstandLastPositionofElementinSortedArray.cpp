#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

void firstpostion(vector<int>& nums, int &target, int &firstoccurence)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]==target)
        {
            firstoccurence=mid;
            e=mid-1;
        }
        else if(nums[mid]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}

void lastposition(vector<int>& nums, int &target, int &lastoccurence)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]==target)
        {
            lastoccurence=mid;
            s=mid+1;
        }
        else if(nums[mid]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
vector<int> searchRange(vector<int>& nums, int &target) {
        int firstoccurence=-1;
        int lastoccurence=-1;
        firstpostion(nums,target,firstoccurence);
        lastposition(nums,target,lastoccurence);
        return {firstoccurence,lastoccurence};

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

    int x;
    cout<<"Enter the value of X: ";
    cin>>x;



    vector<int> result=searchRange(arr,x);
    for(int val:result)
    {
        cout<<val<<" ";
    }
    return 0;
    
   
}