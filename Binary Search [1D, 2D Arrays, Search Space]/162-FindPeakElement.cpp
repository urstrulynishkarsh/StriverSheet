#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]<nums[mid+1])
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

   

    cout<<findPeakElement(arr);

    return 0;
    
   
}