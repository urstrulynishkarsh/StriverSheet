#include<iostream>
#include<string.h>
using namespace std;

bool palindrome(string &s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                bool firstanswer=palindrome(s,i+1,j);
                bool secondanswer=palindrome(s,i,j-1);
                return firstanswer||secondanswer;
            }
        }
        return true;
    }
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<validPalindrome(str);
}