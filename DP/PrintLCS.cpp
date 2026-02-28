#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


 int solve(string &text1, string &text2, int i, int j,vector<vector<int> >&dp)
    {
        if(i>=text1.length())
        {
            return 0;
        }
        if(j>=text2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j])
        {
            ans=1+solve(text1,text2,i+1,j+1,dp);
        }
        else{
            ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }

      string printLCS(string &str1, string &str2,vector<vector<int> >&dp)
    {
      int i=0,j=0;
      string ans;
      while(i<str1.length() && j< str2.length())
      {
          if(str1[i]==str2[j])
          {
              ans.push_back(str1[i]);
              i++;
              j++;
          }
          else if(dp[i+1][j]>dp[i][j+1])
          {
            i++;
          }
          else{
            j++;
          }
      }
      return ans;
    }
int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);

    string t;
    cout<<"Enter the t string: ";
    getline(cin,t);


vector<vector<int> >dp(s.length()+1,vector<int>(t.length()+1,-1));

  solve(s,t,0,0,dp);
  cout<<printLCS(s,t,dp);
}