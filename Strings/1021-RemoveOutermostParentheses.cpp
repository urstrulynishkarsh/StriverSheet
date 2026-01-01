#include<iostream>
#include<string.h>
using namespace std;

string removeOuterParentheses(string &str)
{
    string ans;
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(' && count==0)
        {
            count++;
        }
        else if(ch=='(' && count>=1)
        {
            ans+=ch;
            count++;
        }
        else if(ch==')' && count>1)
        {
            ans+=ch;
            count--;
        }
        else{
            count--;
        }
    }
    return ans;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<removeOuterParentheses(str);
}