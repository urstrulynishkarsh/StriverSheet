#include<iostream>
#include<vector>
using namespace std;

int solve(int i, int j, vector<int>& nums1, vector<int>& nums2,vector<vector<int>  >&dp)
    {
        if(i>=nums1.size() || j>=nums2.size())
        {
            return -1e9+7;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int ans=INT_MIN;
        // take both value
        int take=nums1[i]*nums2[j]+ max(0,solve(i+1,j+1,nums1,nums2,dp));
        ans=max(ans,take);

        // skip1
        int skip1=solve(i+1,j,nums1,nums2,dp);
        ans=max(ans,skip1);

        // skip2
        int skip2=solve(i,j+1,nums1,nums2,dp);
        ans=max(ans,skip2);

        return dp[i][j]=ans;

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int> >dp(n+1,vector<int> (m,-1));
        return solve(0,0,nums1,nums2,dp);
    }
int main()
{
    int m;
    cout<<"Enter the m size: ";
    cin>>m;

    int n;
    cout<<"Enter the n size: ";
    cin>>n;

    int totalsize=n+m;
    vector<int> nums1(totalsize);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
    for(int i=m;i<totalsize;i++)
    {
        nums1[i]=0;
    }
    vector<int> nums2(n);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    cout<<maxDotProduct(nums1,nums2);
       
}