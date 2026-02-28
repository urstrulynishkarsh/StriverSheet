#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


 int solveRecursion(string &word1, string &word2,int i, int j,vector<vector<int>> &dp)
    {
        if(i==word1.length())
        {
            return 0;
        }
        if(j==word2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j])
        {
            ans=1+solveRecursion(word1,word2,i+1,j+1,dp);
        }
        else{
            ans=max(solveRecursion(word1,word2,i+1,j,dp),solveRecursion(word1,word2,i,j+1,dp));
        }
        return dp[i][j] =ans;
    }
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        int i=0;
        int j=0;
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        int lcsvalue=solveRecursion(s,t,i,j,dp);
        return lcsvalue;

    }

int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);
    cout<<longestPalindromeSubseq(s);
}