#include<iostream>
#include<string.h>
using namespace std;

string removealladjacent(string &str)
{
    string ans;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ans.empty())
        {
            ans.push_back(ch);
        }
        else if(ans.back()==ch)
        {
            ans.pop_back();
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<removealladjacent(str);
}