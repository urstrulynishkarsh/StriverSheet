#include<iostream>
#include<vector>
using namespace std;

int SearchInRotated(vector<int> &nums, int target)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[s]<=nums[mid])
        {
            if(nums[s]<=target && target<nums[mid])
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[e])
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
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
    cout<<"Enter the value of X: ";
    cin>>k;

    cout<<SearchInRotated(arr,k);
}