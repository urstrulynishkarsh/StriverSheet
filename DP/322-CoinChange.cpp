#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


 int solveRecursion(vector<int>& coins, int amount,vector<int> &dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0)
        {
            return INT_MAX;
        }
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int ans=solveRecursion(coins,amount-coins[i],dp);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
        }
        return dp[amount]=mini;

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
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;
    

    vector<int> dp(amount+1,-1);
        int ans=solveRecursion(arr,amount,dp);
        if(ans!=INT_MAX)
        {
            cout<<ans;
        }
        else{
            cout<<-1;
        }



    
    
   
}