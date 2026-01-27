#include<iostream>
#include<string.h>
#include<string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.length();
        int k=p.length();
        unordered_map<char,int> mp;
        for(char &ch:p)
        {
            mp[ch]++;
        }
        int count=mp.size();
        // cout<<count;
        int i=0,j=0;
        while(j<n)
        {
            // calculation
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }

            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k){
                // store result
                if(count==0)
                {
                    ans.push_back(i);
                }

                // shift window
                 if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {   
                    count++;
                    }
                }
                i++;
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




    vector<int> result=findAnagrams(s,t);
    for(int val:result)
    {
        cout<<val<<" ";
    }
}