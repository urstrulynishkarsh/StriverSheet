#include<iostream>
#include<vector>
using namespace std;

long long maxMatrixSum(vector<vector<int> > &matrix)
{
    long long sum=0;
    long long smallest=INT_MAX;
    long long count=0;
    int row=matrix.size();
    int col=matrix[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]<0)
            {
                count++;
            }
            long long value=abs(matrix[i][j]);
            smallest=min(smallest,value);
            sum+=value;
        }
    }
    if(count&1)
    {
        return sum-2*smallest;
    }
    return sum;
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
    

    

  
    cout<<maxMatrixSum(matrix);




    

}