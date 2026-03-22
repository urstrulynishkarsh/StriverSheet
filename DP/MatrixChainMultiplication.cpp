#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


int solveRecursion(vector<int> &arr, int i, int j, vector<vector<int> > &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solveRecursion(arr,i,k,dp)+solveRecursion(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=1;
        int j=arr.size()-1;
        vector<vector<int> >dp(n+1,vector<int> (n+1,-1));
        return solveRecursion(arr,i,j,dp);
        
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
    cout<< matrixMultiplication(nums);
}