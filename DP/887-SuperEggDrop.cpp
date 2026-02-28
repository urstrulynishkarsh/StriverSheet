#include<iostream>
#include<vector>
using namespace std;

int solveRecursion(int e, int f, vector<vector<int> > &dp)
    {
        if(e==1 || f==0 || f==1)
        {
            return f;
        }
        if(dp[e][f]!=-1)
        {
            return dp[e][f];
        }
        int ans=INT_MAX;
        int start=1;
        int end=f;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            // break
            int left=solveRecursion(e-1,mid-1,dp);

            // not break
            int right=solveRecursion(e,f-mid,dp);

            int temp=1+max(left,right);

            if(left<right)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[e][f]=ans;
}
int main()
{
    int egg;
    cout<<"Enter the number of egg: ";
    cin>>egg;

    int flooor;
    cout<<"Enter the number of floor: ";
    cin>>flooor;


    vector<vector<int> >dp(egg+1,vector<int> (flooor+1,-1));
    cout<<solveRecursion(egg,flooor,dp);




}