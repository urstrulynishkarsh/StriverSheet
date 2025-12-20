#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if( nums[mid]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
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

    int k;
    cout<<"Enter the value of X: ";
    cin>>k;

    cout<<searchInsert(arr,k);

    return 0;
    
   
}