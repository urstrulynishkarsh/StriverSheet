#include<iostream>
#include<string.h>
using namespace std;

string largestODDNumber(string &str)
{
    int j=str.length()-1;
    while(j>=0)
    {
        if(int(str[j])&1)
        {
            return str.substr(0,j+1);
        }
        j--;
    }
    return "";
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<largestODDNumber(str);
}