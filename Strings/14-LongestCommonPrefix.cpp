#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


string LCP(vector<string> &strs)
{
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[strs.size()-1];
    string ans;
    for(int i=0;i<last.length();i++)
    {
        if(first[i]==last[i])
        {
            ans.push_back(first[i]);
        }
        else{
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the no of string: ";
    cin>>n;
    vector<string> strs;
    cout<<"Enter the string: ";
    while(n--)
    {
        string str;
        cin>>str;
        strs.push_back(str);
    }

    cout<<LCP(strs);
}