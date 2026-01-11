#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int solve(string &s, string &t,int i, int j,vector<vector<int> > &dp)
{
    if(i>=s.length())
    {
        int sum=0;
        for(int k=j;k<t.length();k++)
        {
            sum+=t[k];
        }
        return sum;
    }
    if(j>=t.length())
    {
        int sum=0;
        for(int k=i;k<s.length();k++)
        {
            sum+=s[k];
        }
        return sum;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==t[j])
    {
        return solve(s,t,i+1,j+1,dp);
    }
    int delete1=s[i]+solve(s,t,i+1,j,dp);
    int delete2=t[j]+solve(s,t,i,j+1,dp);
    return dp[i][j]=min(delete1,delete2);
}
int main()
{
    string s;
    cout<<"Enter the s1 string: ";
    getline(cin,s);

    string t;
    cout<<"Enter the s2 string: ";
    getline(cin,t);


     vector<vector<int> > dp(s.length()+1,vector<int> (t.length()+1,-1));
    cout<<solve(s,t,0,0,dp);

}