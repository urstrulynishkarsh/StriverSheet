#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


bool possibleSolution(vector<int> &nums, int k, int mid)
{
    int c=1;
    int pos=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]-pos>=mid)
        {
            c++;
            pos=nums[i];
        }
        if(c==k)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &nums, int k)
{
    sort(nums.begin(),nums.end());
    int s=0;
    int e=nums[nums.size()-1]-nums[0];
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(possibleSolution(nums,k,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
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

    cout<<aggressiveCows(arr,k);

    return 0;
    
   
}