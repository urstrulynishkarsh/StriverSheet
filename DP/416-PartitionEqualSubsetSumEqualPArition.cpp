#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<limits.h>
#include <numeric>
using namespace std;


bool solveRecursion(vector<int>& arr, int sum, int n,vector<vector<int> >&dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        
        if(arr[n-1]<=sum)
        {
           return dp[n][sum]= solveRecursion(arr,sum-arr[n-1],n-1,dp)||solveRecursion(arr,sum,n-1,dp);
        }
        else{
            return dp[n][sum]=solveRecursion(arr,sum,n-1,dp);;
        }
    }
    bool isSubsetSum(vector<int>& nums) {
        // code here
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(totalsum % 2 != 0)   // 🔥 IMPORTANT
            return false;
        int sum=totalsum/2;
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int> (sum+1,-1));
        return solveRecursion(nums,sum,n,dp);
        
    }


int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
   
    cout<< isSubsetSum(nums);
}