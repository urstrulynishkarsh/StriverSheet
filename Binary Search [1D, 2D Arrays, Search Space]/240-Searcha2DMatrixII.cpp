#include<iostream>
#include<vector>
using namespace std;

bool searchinmatrix( vector<vector<int> > &matrix, int target)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int row=0;
    int col=n-1;
    while(row<m && col>=0)
    {
        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]>target)
        {
            col--;
        }
        else{
            row++;
        }
    }
    return false;
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

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

  
    cout<<searchinmatrix(matrix,target);




    

}