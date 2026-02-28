#include<iostream>
#include<vector>
using namespace std;


 int solveRecursion(vector<int>& nums1, vector<int>& nums2, int i, int j,vector<vector<int> > &dp)
    {
        if(i>=nums1.size())
        {
            return 0;
        }
         if(j>=nums2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(nums1[i]==nums2[j])
        {
            ans=1+solveRecursion(nums1, nums2, i+1,j+1,dp);
        }
        return dp[i][j]=ans;
    }
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums1(n);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums1[i];
    }

    vector<int> nums2(n);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    

    vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    maxi=max(maxi,solveRecursion(nums1,nums2,i,j,dp));
                }
            }
        }
        cout<<maxi;

   

}