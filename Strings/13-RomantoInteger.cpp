#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int romanToInt(string &str)
{
    unordered_map<char,int> hashmap{
        {'I',1},
        {'V',5},
        {'X' ,10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
        if(hashmap[str[i]]<hashmap[str[i+1]])
        {
            ans-=hashmap[str[i]];
        }
        else{
            ans+=hashmap[str[i]];
        }
    }
    return ans;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    

    cout<<romanToInt(str);

}