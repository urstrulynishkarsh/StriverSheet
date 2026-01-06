#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int STOI(string &s)
{
    long num=0;
    int i=0;
    int sign=1;
    int n=s.length();

    while(s[i]==' ')
    {
        i++;
    }
    if(i<n && (s[i]=='+' || s[i]=='-'))
    {
        sign=(s[i]=='+')?1:-1;
        i++;
    }
    while(i<n && isdigit(s[i]))
    {
        num=num*10+(s[i]-'0');
        if(sign==1 && num>INT_MAX)
        {
            return INT_MAX;
        }
        if(sign==-1 && -num<INT_MIN)
        {
            return INT_MIN;
        }
        i++;
    }
    return num*sign;
}

int main()
{
   string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    

    cout<<STOI(str);

}