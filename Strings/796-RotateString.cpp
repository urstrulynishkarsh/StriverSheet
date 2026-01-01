#include<iostream>
#include<string.h>
#include<string>
using namespace std;

bool rotateString(string &s, string &goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }
       return (s + s).find(goal) != string::npos;
    }
int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);

    string t;
    cout<<"Enter the t string: ";
    getline(cin,t);




    cout<<rotateString(s,t);
}