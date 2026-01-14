#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums, int i,vector<int> &dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int inclusion=nums[i]+solve(nums,i+2,dp);
        int exclusion=0+solve(nums,i+1,dp);
        return dp[i]=max(inclusion,exclusion);
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
        
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
    cout<<rob(arr);
}