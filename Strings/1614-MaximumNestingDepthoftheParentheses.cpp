#include<iostream>
#include<string.h>
using namespace std;

int maxDepth(string &str)
{
    int curr=0;
    int maxlength=0;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(')
        {
            curr++;
            maxlength=max(maxlength,curr);
        }
        else if(ch==')'){
            curr--;
        }

    }
    return maxlength;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    

    cout<<maxDepth(str);

}