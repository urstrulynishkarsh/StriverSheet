#include<iostream>
#include<string.h>
using namespace std;

string reverseWords(string &str)
{
    reverse(str.begin(),str.end());
    int i=0;
    int start=0;
    int end=0;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        while(i<n && str[i]==' ')
        {
            i++;
        }
        if(i==n)
        {
            break;
        }
        while(i<n && str[i]!=' ')
        {
            str[end++]=str[i++];
        }
        reverse(str.begin()+start,str.begin()+end);
        str[end++]=' ';
        start=end;
    }
    str.resize(end-1);
    return str;

}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<reverseWords(str);
}