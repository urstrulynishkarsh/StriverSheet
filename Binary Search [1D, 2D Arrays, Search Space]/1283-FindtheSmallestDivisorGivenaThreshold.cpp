#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

long long calculatesum(vector<int> &nums , int divisor)
{
    long long sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=ceil((double)nums[i]/(double)divisor);
    }
    return sum;
}
int smallestDivisor(vector<int> &nums , int threshold)
{
    int maxi=INT_MIN;
    for(int val:nums)
    {
        if(val>maxi)
        {
            maxi=val;
        }
    }
    int s=1;
    int e=maxi;
    int ans=-1;

    while(s<=e)
    {
        int mid=(s+e)>>1;
        long long sum=calculatesum(nums,mid);
        if(sum<=threshold)
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

    cout<<smallestDivisor(arr,h);

    return 0;
    
   
}