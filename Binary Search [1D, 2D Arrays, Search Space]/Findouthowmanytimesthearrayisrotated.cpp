#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int findKRotationLinear(vector<int> &nums)
{
    int minindex=0;
    int min=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(min>nums[i])
        {
            min=nums[i];
            minindex=i;
        }
    }
    return minindex;
}

int findKRotation(vector<int> &nums)
{
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[s]<=nums[e])
        {
            return s;
        }
        if(nums[mid]>nums[e])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
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

   

    // cout<<findKRotationLinear(arr);
    cout<<findKRotation(arr);

    return 0;
    
   
}