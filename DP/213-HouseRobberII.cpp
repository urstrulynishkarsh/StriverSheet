#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums, int i,int end,vector<int> &dp )
    {
        if(i>=end)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int include=nums[i]+solve(nums,i+2,end,dp);
        int exclude=0+solve(nums,i+1,end,dp);
        return dp[i]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int ans1=solve(nums,0,n-1,dp1);
        int ans2=solve(nums,1,n,dp2);
        return max(ans1,ans2);
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