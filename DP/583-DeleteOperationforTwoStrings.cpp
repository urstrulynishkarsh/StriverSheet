#include<iostream>
#include<string.h>
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
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        int lcsvalue=solveRecursion(word1,word2,i,j,dp);
        
        return n+m-(2*lcsvalue);
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