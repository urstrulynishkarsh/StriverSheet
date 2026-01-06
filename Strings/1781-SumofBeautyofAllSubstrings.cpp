#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int beautySum(string &s)
{
    int beautysum=0;
    unordered_map<char,int> hashmap;
    for(int i=0;i<s.length();i++)
    {
        hashmap.clear();
        for(int j=i;j<s.length();j++)
        {
            char &ch=s[j];
            hashmap[ch]++;

            int maxi=INT_MIN;
            int mini=INT_MAX;

            for(auto it:hashmap)
            {
                maxi=max(maxi,it.second);
                mini=min(mini,it.second);
            }
            beautysum+=maxi-mini;
        }
    }
    return beautysum;
}

int main()
{
   string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    

    cout<<beautySum(str);

}