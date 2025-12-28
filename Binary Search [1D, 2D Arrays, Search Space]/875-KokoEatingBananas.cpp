#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

long long calculatetotalhrs(vector<int>& nums, int h)
{
    long long totalhrs=0;
    for(int i=0;i<nums.size();i++)
    {
        totalhrs+=ceil((double)nums[i]/(double)h);
    }
    return totalhrs;
}
int minEatingSpeed(vector<int>& nums, int &h) {
    int maxi=INT_MIN;
    for(int val:nums)
    {
        if(maxi<val)
        {
            maxi=val;
        }
    }

    int s=1;
    int e=maxi;
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        long long totalhrs=calculatetotalhrs(nums,mid);
        if(totalhrs<=h)
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

    int h;
    cout<<"Enter the value of h: ";
    cin>>h;

    cout<<minEatingSpeed(arr,h);

    return 0;
    
   
}