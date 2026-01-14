#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& height, int i,vector<int> &dp)
    {
        if(i==height.size()-1)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int cost1=abs(height[i]-height[i+1])+solve(height,i+1,dp);
        int cost2=INT_MAX;
        if(i+2<height.size())
        {
            cost2=abs(height[i]-height[i+2])+solve(height,i+2,dp);
        }
        return dp[i]= min(cost1,cost2);
    }
    int frogJump(vector<int>& height) {
        int i=0;
        vector<int> dp(height.size()+1,-1);
        return solve(height,i,dp);
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
    cout<<frogJump(arr);
}