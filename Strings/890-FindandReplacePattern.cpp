#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string> &words, string &t)
{
    vector<string> result;
    for(int i=0;i<words.size();i++)
    {
        string s=words[i];
         int hash[256]={0};
    char charmapped[256]={0};
    for(int j=0;j<s.length();j++)
    {
        if(hash[s[j]]==0 && charmapped[t[j]]==0)
        {
            hash[s[j]]=t[j];
            charmapped[t[j]]=true;
        }
    }
    for(int j=0;j<s.length();j++)
    {
        if(char(hash[s[j]])!=t[j])
        {
            break;
        }
        if(j==s.length()-1)
        {
            result.push_back(s);
        }
    }
    }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the no of string: ";
    cin>>n;
    vector<string> words;
    cout<<"Enter the string: ";
    while(n--)
    {
        string str;
        cin>>str;
        words.push_back(str);
    }
    string pattern;
    cout<<"Enter the pattern: ";
    cin>>pattern;
    
    vector<string> result=findAndReplacePattern(words,pattern);

    for(auto str:result)
    {
        cout<<str<<" ";
    }

    return 0;
   
}