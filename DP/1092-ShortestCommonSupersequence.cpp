#include<iostream>
#include<string.h>
using namespace std;


 int LCS(string &text1, string &text2, int i, int j,vector<vector<int> >&dp)
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
            ans=1+LCS(text1,text2,i+1,j+1,dp);
        }
        else{
            ans=max(LCS(text1,text2,i+1,j,dp),LCS(text1,text2,i,j+1,dp));
        }
        return dp[i][j]=ans;
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
    int lcslength=LCS(s,t,0,0,dp);
    int finallength=s.length()+t.length()-lcslength;
    cout<<finallength<<endl;

    int i=0;
    int j=0;
    string ans;

    while(i<s.length() && j<t.length())
    {
        if(s[i]==t[j])
        {
            ans.push_back(s[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            ans.push_back(s[i]);
            i++;
        }
        else{
            ans.push_back(t[j]);
            j++;
        }
    }
    while(i<s.length())
    {
        ans.push_back(s[i]);
        i++;
    }
    while(j<t.length())
    {
        ans.push_back(t[j]);
        j++;
    }

    cout<<ans<<endl;


}