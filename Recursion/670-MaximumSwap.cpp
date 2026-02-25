#include<iostream>
#include<string.h>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    string s=to_string(n);
    string result=s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            swap(s[i],s[j]);
            result=max(result,s);
            swap(s[i],s[j]);
        }
    }
    cout<<stoi(result);
}
