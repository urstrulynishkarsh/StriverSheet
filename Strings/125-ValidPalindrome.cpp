#include<iostream>
#include<string.h>
using namespace std;

bool ValidPalindrome(string &str)
{
    int i=0;
    int j=str.length()-1;
    while(i<=j)
    {
        if(!isalnum(str[i]))
        {
            i++;
            continue;
        }
        if(!isalnum(str[j]))
        {
            j--;
            continue;
        }
        if(tolower(str[i])!=tolower(str[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<ValidPalindrome(str);
}