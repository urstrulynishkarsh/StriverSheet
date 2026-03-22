#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int LCS(string &s,string &t, int i, int j, vector<vector<int> > &dp)
    {
        if(i==s.length())
        {
            return 0;
        }
        if(j==t.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j] && i!=j)
        {
            ans=1+LCS(s,t,i+1,j+1,dp);
        }
        else{
            ans=max(LCS(s,t,i+1,j,dp),LCS(s,t,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        string t(s.rbegin(),s.rend());
        vector<vector<int> > dp(s.length()+1,vector<int> (t.length()+1,-1));
        return LCS(s,t,0,0,dp);
    }

int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);
    cout<<LongestRepeatingSubsequence(s);
}