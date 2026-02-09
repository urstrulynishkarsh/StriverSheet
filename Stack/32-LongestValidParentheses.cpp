#include<iostream>
#include<string.h>
#include<stack>
using namespace std;


int longestvalidparenthesis(string &str)
{
    int maxlength=0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(')
        {
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            int len=i-st.top();
            maxlength=max(maxlength,len);
        }
    }
    return maxlength;

}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<longestvalidparenthesis(str);
}