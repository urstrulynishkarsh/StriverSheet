#include<iostream>
#include<string.h>
using namespace std;

bool isAnagram(string s, string t) {
        unordered_map<char,int> hashmap;
        for(int i=0;i<s.length();i++)
        {
            hashmap[s[i]]++;
        }
        for(auto ch:t)
        {
            hashmap[ch]--;
        }
        for(auto mp:hashmap)
        {
            if(mp.second!=0)
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




    cout<<isAnagram(s,t);
}