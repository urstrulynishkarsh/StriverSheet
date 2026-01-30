#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

string minWindow(string s, string t) {
        // pre requirement
        unordered_map<char, int> mp;
        for(char ch:t)
        {
            mp[ch]++;
        }
        int minlength=INT_MAX;
        int start=0;
        int i=0;
        int j=0;
        int count=mp.size();
        int n=s.length();


        // code start
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        {
                            count++;
                            if(j-i+1<minlength)
                            {
                                minlength=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(minlength==INT_MAX)
        {
            return "";
        }
        return s.substr(start,minlength);
    }
int main()
{
    string key;
    cout<<"Enter the key string: ";
    getline(cin,key);

    string message;
    cout<<"Enter the message: ";
    getline(cin,message);

    cout<<minWindow(key,message);
}