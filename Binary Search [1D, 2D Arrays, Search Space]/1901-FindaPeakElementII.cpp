#include<iostream>
#include<vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int row=mat.size();
    int col=mat[0].size();
    int s=0;
    int e=col-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int maxrow=0;
        for(int i=0;i<row;i++)
        {
            if(mat[i][mid]>mat[maxrow][mid])
            {
                maxrow=i;
            }
        }
        int left=(mid-1>=0)?mat[maxrow][mid-1]:-1;
        int right=(mid+1<col)?mat[maxrow][mid+1]:-1;
        int center=mat[maxrow][mid];
        if(left<center && center>right)
        {
            return {maxrow,mid};
        }
        else if(left>center)
        {
            e=mid-1;
        }
        else if(right>center)
        {
            s=mid+1;
        }
    }
    return {-1,-1};
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
  
    vector<int> ans=findPeakGrid(matrix);
    for(int val:ans)
    {
        cout<<val<<" ";
    }

}