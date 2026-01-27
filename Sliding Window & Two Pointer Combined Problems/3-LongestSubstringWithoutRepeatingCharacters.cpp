#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.empty())
        {
            return 0;
        }
        int i=0;
        int j=0;
        int n=s.size();
        int maxi=INT_MIN;
        unordered_map<int, int> mp;
        while(j<n)
        {
            // calculation
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
int main()
{
 

    string message;
    cout<<"Enter the message: ";
    getline(cin,message);

    cout<<lengthOfLongestSubstring(message);
}