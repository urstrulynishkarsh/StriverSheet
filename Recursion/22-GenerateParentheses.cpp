#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void solveRecursion(int n, int open, int close,vector<string> &result, string output)
{
    // base case
    if(open==0 && close==0)
    {
        result.push_back(output);
        return;
    }

    if(open>0)
    {
        output.push_back('(');
        solveRecursion(n,open-1,close,result,output);
        output.pop_back();
    }
    if(close>open)
    {
        output.push_back(')');
        solveRecursion(n,open,close-1,result,output);
        output.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;


    vector<string> result;
    string output;
    int open=n;
    int close=n;

    solveRecursion(n,open,close,result,output);

    for(auto str: result)
    {
        cout<<str<<" ";
    }
}