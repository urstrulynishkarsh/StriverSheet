#include<iostream>
#include<string.h>
#include<stack>
using namespace std;


void reverseString(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);

    reverseString(s);
}