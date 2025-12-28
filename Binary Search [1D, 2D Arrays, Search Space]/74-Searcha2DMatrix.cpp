#include<iostream>
#include<vector>
using namespace std;

bool searchinmatrix( vector<vector<int> > &matrix, int target)
{
    int row=matrix.size();
    int col=matrix[0].size();
    int s=0;
    int e=(row*col)-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        int i=mid/col;
        int j=mid%col;
        if(matrix[i][j]==target)
        {
            return true;
        }
        else if(matrix[i][j]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
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