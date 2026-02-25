#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void solveRecursion(int n, vector<string> &result, string temp)
    {
        if(temp.length()==n)
        {
            result.push_back(temp);
            return;
        }
        solveRecursion(n,result,temp+'0');
        if(temp.empty() || temp.back()!='1')
        {
            solveRecursion(n,result,temp+'1');
        }
    }
    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
        vector<string> result;
        string temp;
        solveRecursion(n,result,temp);
        return result;
    }

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<string> ans=generateBinaryStrings(n);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
}