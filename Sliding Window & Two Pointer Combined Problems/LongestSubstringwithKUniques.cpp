#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longestKSubstr(string &s, int k) {
        // code here
        int maxi=-1;
        int i=0;
        int j=0;
        int n=s.length();
        unordered_map<int,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==k)
            {
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
int main()
{
     string message;
    cout<<"Enter the message: ";
    getline(cin,message);
   
    int k;
    cout<<"Enter the k value";
    cin>>k;
    cout<<longestKSubstr(message,k);
}