#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

string DecodeMessage(string &key, string &message)
{   
    unordered_map<char,char> hashmap;
    char start='a';
    for(char ch:key)
    {
        if(ch!=' ' && hashmap.find(ch)==hashmap.end())
        {
            hashmap[ch]=start++;
            if(start>'z')
            {
            break;
            }
        }
    }

    string ans;
    for(char ch:message)
    {
        if(ch==' ')
        {
            ans+=' ';
        }
        else{
            ans+=hashmap[ch];
        }
    }
    return ans;
}
int main()
{
    string key;
    cout<<"Enter the key string: ";
    getline(cin,key);

    string message;
    cout<<"Enter the message: ";
    getline(cin,message);

    cout<<DecodeMessage(key,message);
}