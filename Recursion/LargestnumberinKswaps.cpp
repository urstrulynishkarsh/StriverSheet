#include<iostream>
#include<string.h>
using namespace std;


void solverecursion(string &s, string &result, int k, int index)
    {
        // base case
        if(k==0 || index>=s.length())
        {
            if(result<s)
            {   
                result=s;
                
            }
            return;
        }
        char maxi=s[index];
        for(int i=index+1;i<s.length();i++)
        {
            if(s[i]>maxi)
            {
                maxi=s[i];
            }
        }
        if (maxi==s[index])
        {
            solverecursion(s,result,k,index+1);
            return;
        }
        
        for(int j=index+1;j<s.length();j++)
        {
            if(s[j]==maxi)
            {
                swap(s[j],s[index]);
                solverecursion(s,result,k-1,index+1);
                swap(s[j],s[index]);
            }
        }
        
        
        
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string result;
        solverecursion(s,result,k,0);
        return result;
    }
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    cout<<findMaximumNum(str,k);
}