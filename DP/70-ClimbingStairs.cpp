#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int> &dp)
    {
        if(n==0)
        {
            return 1;
        }
         dp[0]=1;
        if(n==1)
        {
            return 1;
        }
        dp[1]=1;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=solve(n-1,dp)+solve(n-2,dp); 
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        return solve(n,dp);
    }

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<climbStairs(n);
}