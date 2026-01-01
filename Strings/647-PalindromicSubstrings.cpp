#include<iostream>
#include<string.h>
using namespace std;


   int expandaroundcenter(string &s,int i, int j)
   {
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
   }
    int countPalindromicSubstring(string &s) {
        int totalcount=0;
        for(int center=0;center<s.length();center++)
        {
            int i=center;
            int j=center;
            int oddlengthsubstring=expandaroundcenter(s,i,j);

            i=center;
            j=center+1;
            int evenlengthsubstring=expandaroundcenter(s,i,j);

            totalcount+=oddlengthsubstring+ evenlengthsubstring;
        }
        return totalcount;
    }
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<countPalindromicSubstring(str);
}