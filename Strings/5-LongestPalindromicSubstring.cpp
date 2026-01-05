#include<iostream>
#include<string.h>
using namespace std;


bool checkpalindrome(string s, int i, int j)
{
    while(i<=j)
    {
        if(s[i++]!=s[j--])
        {
            return false;
        }
    }
    return true;
}
string longestPalindrome(string &s) {
    int start=0;
    int maxlength=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++)
        {
            if(checkpalindrome(s,i,j))
            {
                if(j-i+1>maxlength)
                {
                    maxlength=j-i+1;
                    start=i;
                }
            }
        }
    }
    return s.substr(start,maxlength);
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<longestPalindrome(str);
}