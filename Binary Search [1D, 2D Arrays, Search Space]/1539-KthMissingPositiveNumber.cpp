#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int findKthPositive(vector<int> &nums, int k)
{
    int s=0;
     int e=nums.size()-1;
     while(s<=e)
     {
        int mid=(s+e)>>1;
        int missing=nums[mid]-(mid+1);
        if(missing<k)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
     }
     return s+k;
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

    cout<<findKthPositive(arr,k);

    return 0;
    
   
}