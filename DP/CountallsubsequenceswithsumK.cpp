#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

bool solveRecursion(int n, int i, vector<int> &arr,int k, int sum,vector<vector<int> > &dp)
{
    // base case
    if(sum==k)
    {
        return true;
    }
    if(sum>k|| n==i)
    {
        return false;
    }
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }

    int take=solveRecursion(n,i+1,arr,k,sum+arr[i],dp);
    int nottake=solveRecursion(n,i+1,arr,k,sum,dp);

    return dp[i][sum]=take||nottake;
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
    cout<<"Enter the k value: ";
    cin>>k;
    

    vector<vector<int> > dp(n,vector<int> (k+1,-1));
    cout<<solveRecursion(n,0,arr,k,0,dp);
        



    
    
   
}