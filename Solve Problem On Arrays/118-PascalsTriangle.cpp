#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >pascalTriangle(int &numrows)
{
    vector<vector<int> > ans;
    for(int i=0;i<numrows;i++)
    {
        vector<int> row(i+1,1);
        for(int j=1;j<i;j++)
        {
            row[j]=ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(row);
    }
    return ans;
}
int main()
{
    int numrows;
    cout<<"Enter the numrows: ";
    cin>>numrows;

    vector<vector<int> >result=pascalTriangle(numrows);

    cout<<"[";
    for(auto arr:result)
    {
        cout<<"[";
        for(int val:arr)
        {
            cout<<val<<",";
        }
        cout<<"],";
    }
    cout<<"]";
}