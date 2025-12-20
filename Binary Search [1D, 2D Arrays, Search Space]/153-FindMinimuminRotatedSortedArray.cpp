#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int findMin(vector<int>& nums) {
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]>nums[e])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return nums[s];
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

   

    cout<<findMin(arr);

    return 0;
    
   
}