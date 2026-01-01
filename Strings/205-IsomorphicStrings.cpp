#include<iostream>
#include<string.h>
using namespace std;

bool checkisomorphic(string &s, string &t)
{
    int hash[256]={0};
    char charmapped[256]={0};
    for(int i=0;i<s.length();i++)
    {
        if(hash[s[i]]==0 && charmapped[t[i]]==0)
        {
            hash[s[i]]=t[i];
            charmapped[t[i]]=true;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(char(hash[s[i]])!=t[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);

    string t;
    cout<<"Enter the t string: ";
    getline(cin,t);




    cout<<checkisomorphic(s,t);
}