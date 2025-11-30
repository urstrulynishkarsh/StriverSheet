#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int upperBound(vector<int> &nums, int x){
    int s=0;
    int e=nums.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(nums[mid]>x)
        {
            ans=mid;
            e=mid-1;
            
        }
        else{
            s=mid+1;
        }
    }
    return ans;
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

    cout<<upperBound(arr,k);

    return 0;
    
   
}