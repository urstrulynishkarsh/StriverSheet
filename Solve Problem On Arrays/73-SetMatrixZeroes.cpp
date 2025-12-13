#include<iostream>
#include<vector>
using namespace std;

void setZero(vector<vector<int> > &matrix, int &n, int &m)
{
    bool rowzero=false;
    bool colzero=false;

    for(int i=0;i<n;i++)
    {
        if(matrix[i][0]==0)
        {
            rowzero=true;
            break;
        }
    }
    for(int j=0;j<m;j++)
    {
        if(matrix[j][0]==0)
        {
            colzero=true;
            break;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        if(matrix[i][0]==0)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]=0;
            }
        }
    }

    for(int i=1;i<m;i++)
    {
        if(matrix[0][i]==0)
        {
            for(int j=1;j<n;j++)
            {
                matrix[j][i]=0;
            }
        }
    }

    if(rowzero)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][0]=0;
        }
    }
    if(colzero)
    {
        for(int j=0;j<m;j++)
        {
            matrix[0][j]=0;
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter the size of row: ";
    cin>>n;
    cout<<"Enter the size of col: ";
    cin>>m;

    vector<vector<int> >matrix(n,vector<int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
    setZero(matrix, n, m);


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}