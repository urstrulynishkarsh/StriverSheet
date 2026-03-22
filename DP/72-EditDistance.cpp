#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int LCS(string &s,string &t, int i, int j, vector<vector<int> > &dp)
    {
        if(i==s.length())
        {
            return t.length()-j;
        }
        if(j==t.length())
        {
            return s.length()-i;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j])
        {
            ans=LCS(s,t,i+1,j+1,dp);
        }
        else{
            int insertion=1+LCS(s,t,i+1,j,dp);
            int deletion=1+LCS(s,t,i,j+1,dp);
            int replace=1+LCS(s,t,i+1,j+1,dp);
            ans=min(insertion,min(deletion,replace));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string s, string t) {
        vector<vector<int> > dp(s.length()+1,vector<int> (t.length()+1,-1));
        return LCS(s,t,0,0,dp);
    }

int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);
     string t;
    cout<<"Enter the t string: ";
    getline(cin,t);
    cout<<minDistance(s,t);
}